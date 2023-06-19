#pragma once

#include <vector>
#include <iomanip>
#include <sstream>

#define VECTOR_ERR 0.001f
#define M_PI 3.1415926535f

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float InF);
	Vector3(float InX, float InY, float InZ);
	Vector3(const std::vector<float>& InData);
	
	std::string ToString() const;

	void Set(float InX, float InY, float InZ);
	void Normalize();

	static float Distance(const Vector3& Vector1, const Vector3& Vector2); //d = √((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
	static float DistanceSquared(const Vector3& Vector1, const Vector3& Vector2); //d = ((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
	static float Distance2D(const Vector3& Vector1, const Vector3& Vector2); //d = √((x2 - x1)^2 + (y2 - y1)^2)
	static float DistanceSquared2D(const Vector3& Vector1, const Vector3& Vector2); //d = ((x2 - x1)^2 + (y2 - y1)^2)
	static float DotProduct(const Vector3& Vector1, const Vector3& Vector2);
	static float AngleDegrees(const Vector3& Vector1, const Vector3& Vector2);
	static float AngleRadians(const Vector3& Vector1, const Vector3& Vector2);

	float GetMax() const;
	float GetMin() const;

	float Length() const; //d = √(x^2 + y^2 + z^2)
	float LengthSquared() const; //d = x^2 + y^2 + z^2
	float Length2D() const; //d = √(x^2 + y^2)
	float LengthSquared2D() const; //d = (x^2 + y^2)
	
	bool Equals(const Vector3& InVector) const;
	bool IsNearlyZero() const;
	bool IsNearlyUnit() const;
	bool IsNormalized() const;

	static Vector3 ZeroVector();
	static Vector3 OneVector();
	static Vector3 UpVector();
	static Vector3 ForwardVector();
	static Vector3 RightVector();
	static Vector3 CrossProduct(const Vector3& Vector1, const Vector3& Vector2);

	Vector3 GetNormalized() const;

	Vector3 operator-() const; //1.-V
	Vector3 operator+(const Vector3& InVector) const; //2.V + V
	Vector3 operator+(float Scalar) const; //2.V + S
	friend Vector3 operator+(float Scalar, const Vector3& InVector); // 2.S + V
	Vector3& operator+=(const Vector3& InVector); //3.V += V
	Vector3& operator+=(const float Scalar); //3.V += S
	friend float& operator+=(float& Scalar, const Vector3& InVector); //3.S += V
	Vector3 operator-(const Vector3& InVector) const; //4.V - V
	Vector3 operator-(const float Scalar) const; //4.V - S
	Vector3& operator-=(const Vector3& InVector); //5.V -= V
	Vector3& operator-=(const float Scalar); //5.V -= S
	Vector3 operator*(const float Scalar) const; //6.V * S
	friend Vector3 operator*(float Scalar, const Vector3& InVector);//6.S * V
	Vector3& operator*=(float Scalar); //7.V *= S
	friend float& operator*=(float& Scalar, const Vector3& InVector); //7.S *= V
	Vector3 operator/(const Vector3& InVector) const; //8.V / V
	Vector3 operator/(float Scalar) const; //8.V / S
	Vector3& operator/=(const Vector3& InVector); //9.V /= V
	Vector3& operator/=(const float Scalar); //9. V /= S
	bool operator==(const Vector3& InVector) const; //10.V == V
	bool operator!=(const Vector3& InVector) const; //10.V != V
	bool operator>(const Vector3& InVector) const; //10.V > V
	bool operator<(const Vector3& InVector) const; //10.V < V
	bool operator>=(const Vector3& InVector) const; //10.V >= V
	bool operator<=(const Vector3& InVector) const;  //10.V <= V
	friend std::ostream& operator<<(std::ostream& OutOstream, const Vector3& vector);
};

