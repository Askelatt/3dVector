#include "Vector3.h"

Vector3::Vector3() : x(0.f), y(0.f), z(0.f) {}

Vector3::Vector3(float InF) : x(InF), y(InF), z(InF) {}

Vector3::Vector3(float InX, float InY, float InZ) : x(InX), y(InY), z(InZ) {}

Vector3::Vector3(const std::vector<float>& InData)
{
	if (InData.size() == 3)
	{
		x = InData[0];
		y = InData[1];
		z = InData[2];
	}
	else
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}
}

void Vector3::Set(float InX, float InY, float InZ)
{
	x = InX;
	y = InY;
	z = InZ;
}

float Vector3::Distance(const Vector3& Vector1, const Vector3& Vector2)
{
	return std::sqrt(
	(Vector2.x - Vector1.x) * (Vector2.x - Vector1.x) +
		(Vector2.y - Vector1.y) * (Vector2.y - Vector1.y) +
		(Vector2.z - Vector1.z) * (Vector2.z - Vector1.z));
}

float Vector3::DistanceSquared(const Vector3& Vector1, const Vector3& Vector2)
{
	return (Vector2.x - Vector1.x) * (Vector2.x - Vector1.x) +
		(Vector2.y - Vector1.y) * (Vector2.y - Vector1.y) +
		(Vector2.z - Vector1.z) * (Vector2.z - Vector1.z);
}

float Vector3::Distance2D(const Vector3& Vector1, const Vector3& Vector2)
{
	return std::sqrt((Vector2.x - Vector1.x) * (Vector2.x - Vector1.x) + (Vector2.y - Vector1.y) * (Vector2.y - Vector1.y));
}

float Vector3::DistanceSquared2D(const Vector3& Vector1, const Vector3& Vector2)
{
	return (Vector2.x - Vector1.x) * (Vector2.x - Vector1.x) + (Vector2.y - Vector1.y) * (Vector2.y - Vector1.y);
}

float Vector3::Length() const
{
	return std::sqrt((x * x) + (y * y) + (z * z));
}

float Vector3::LengthSquared() const
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3::Length2D() const
{
	return std::sqrt((x * x) + (y * y));
}

float Vector3::LengthSquared2D() const
{
	return (x * x) + (y * y);
}

bool Vector3::Equals(const Vector3& InVector) const
{
	return std::abs(InVector.x - x) <= VECTOR_ERR && std::abs(InVector.y - y) <= VECTOR_ERR && std::abs(InVector.z - z) <= VECTOR_ERR;
}

bool Vector3::IsNearlyZero() const
{
	return std::abs(x) <= VECTOR_ERR && std::abs(y) <= VECTOR_ERR && std::abs(z) <= VECTOR_ERR;
}

bool Vector3::IsNearlyUnit() const
{
	return std::abs(Length() - 1.f) <= VECTOR_ERR;
}

float Vector3::GetMax() const
{
	return std::max(std::max(x, y), z);
}

float Vector3::GetMin() const
{
	return std::min(std::min(x, y), z);
}

void Vector3::Normalize()
{
	float length = Length();
	if (std::abs(length - 1) >= VECTOR_ERR)
	{
		x /= length;
		y /= length;
		z /= length;
	}
}

bool Vector3::IsNormalized() const
{
	return std::abs(Length() - 1) <= VECTOR_ERR;
}

Vector3 Vector3::GetNormalized() const
{
	Vector3 NormalizedVector = *this;
	NormalizedVector.Normalize();
	return NormalizedVector;
}

Vector3 Vector3::ZeroVector()
{
	return { 0.f, 0.f, 0.f };
}

Vector3 Vector3::OneVector()
{
	return { 1.f, 1.f, 1.f };
}

Vector3 Vector3::UpVector()
{
	return { 0.f, 0.f, 1.f };
}

Vector3 Vector3::ForwardVector()
{
	return { 1.f, 0.f, 0.f };
}

Vector3 Vector3::RightVector()
{
	return { 0.f, 1.f, 0.f };
}

std::string Vector3::ToString() const
{
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << "X = " << x << " Y = " << y << " Z = " << z;
	return ss.str();
}

Vector3 Vector3::operator-() const
{
	return { -x, -y, -z };
}

Vector3 Vector3::operator+(const Vector3& InVector) const
{
	return { InVector.x + x, InVector.y + y, InVector.z + z };
}

Vector3 Vector3::operator+(float Scalar) const
{
	return { x + Scalar, y + Scalar, z + Scalar };
}

Vector3& Vector3::operator+=(const Vector3& InVector)
{
	x += InVector.x;
	y += InVector.y;
	z += InVector.z;
	return *this;
}

Vector3& Vector3::operator+=(const float Scalar)
{
	x += Scalar;
	y += Scalar;
	z += Scalar;
	return *this;
}

Vector3 Vector3::operator-(const Vector3& InVector) const
{
	return { x - InVector.x, y - InVector.y, z - InVector.z };
}

Vector3 Vector3::operator-(const float Scalar) const
{
	return { x - Scalar, y - Scalar, z - Scalar };
}

Vector3& Vector3::operator-=(const Vector3& InVector)
{
	x -= InVector.x;
	y -= InVector.y;
	z -= InVector.z;
	return *this;
}

Vector3& Vector3::operator-=(const float Scalar)
{
	x -= Scalar;
	y -= Scalar;
	z -= Scalar;
	return *this;
}

Vector3 Vector3::operator*(const float Scalar) const
{
	return { x * Scalar, y * Scalar, z * Scalar };
}

Vector3& Vector3::operator*=(float Scalar)
{
	x *= Scalar;
	y *= Scalar;
	z *= Scalar;
	return *this;
}

Vector3 Vector3::operator/(const Vector3& InVector) const
{
	if (std::abs(InVector.x) < VECTOR_ERR || std::abs(InVector.y) < VECTOR_ERR || std::abs(InVector.z) < VECTOR_ERR)
	{
		return { INFINITY, INFINITY, INFINITY };
	}
	return { x / InVector.x, y / InVector.y, z / InVector.z };
}

Vector3 Vector3::operator/(float Scalar) const
{
	if (std::abs(Scalar) < VECTOR_ERR)
	{
		return { INFINITY, INFINITY, INFINITY };
	}
	return { x / Scalar, y / Scalar, z / Scalar };
}

Vector3& Vector3::operator/=(const Vector3& InVector)
{
	if (std::abs(InVector.x) < VECTOR_ERR && std::abs(InVector.y) < VECTOR_ERR && std::abs(InVector.z) < VECTOR_ERR)
	{
		x = INFINITY;
		y = INFINITY;
		z = INFINITY;
		return *this;
	}
	x /= InVector.x;
	y /= InVector.y;
	z /= InVector.z;
	return *this;
}

Vector3& Vector3::operator/=(const float Scalar)
{
	if (std::abs(Scalar) < VECTOR_ERR)
	{
		x = 0;
		y = 0;
		z = 0;
		return *this;
	}
	x /= Scalar;
	y /= Scalar;
	z /= Scalar;
	return *this;
}

bool Vector3::operator==(const Vector3& InVector) const
{
	return std::abs(x - InVector.x) <= VECTOR_ERR && std::abs(y - InVector.y) <= VECTOR_ERR && std::abs(z - InVector.z) <= VECTOR_ERR;
}

bool Vector3::operator!=(const Vector3& InVector) const
{
	return !(*this == InVector);
}

bool Vector3::operator>(const Vector3& InVector) const
{
	return this->Length() > InVector.Length();
}

bool Vector3::operator<(const Vector3& InVector) const
{
	return this->Length() < InVector.Length(); 
}

bool Vector3::operator>=(const Vector3& InVector) const
{
	return this->Length() >= InVector.Length();
}

bool Vector3::operator<=(const Vector3& InVector) const
{
	return this->Length() <= InVector.Length();
}

float Vector3::DotProduct(const Vector3& Vector1, const Vector3& Vector2)
{
	return Vector1.x * Vector2.x + Vector1.y * Vector2.y + Vector1.z * Vector2.z;
}

Vector3 Vector3::CrossProduct(const Vector3& Vector1, const Vector3& Vector2)
{
	return	{ Vector1.y * Vector2.z - Vector1.z * Vector2.y,	   //Vector3 = Vector1.y * Vector2.z - Vector1.z * Vector2.y
			  Vector1.z * Vector2.x - Vector1.x * Vector2.z,	   //Vector3 = Vector1.z * Vector2.x - Vector1.x * Vector2.z
			  Vector1.x * Vector2.y - Vector1.y * Vector2.x };      //Vector3 = Vector1.x * Vector2.y - Vector1.y * Vector2.x
}

float Vector3::AngleDegrees(const Vector3& Vector1, const Vector3& Vector2)
{
	Vector3 normalizedVector1 = Vector1.GetNormalized();
	Vector3 normalizedVector2 = Vector2.GetNormalized();
	return std::acos(DotProduct(normalizedVector1, normalizedVector2) / (normalizedVector1.Length() * normalizedVector2.Length())) * (180.0f / M_PI); //θ = acos((a•b) / (|a| * |b|)) * (180/PI)
}

float Vector3::AngleRadians(const Vector3& Vector1, const Vector3& Vector2)
{
	Vector3 normalizedVector1 = Vector1.GetNormalized();
	Vector3 normalizedVector2 = Vector2.GetNormalized();
	return std::acos(DotProduct(normalizedVector1, normalizedVector2) / (normalizedVector1.Length() * normalizedVector2.Length())); //θ = acos((a•b) / (|a| * |b|))
}

Vector3 operator+(float Scalar, const Vector3& InVector)
{
	return { Scalar + InVector.x, Scalar + InVector.y, Scalar + InVector.z };
}

float& operator+=(float& Scalar, const Vector3& InVector)
{
	Scalar += InVector.Length();
	return Scalar;
}

Vector3 operator*(float Scalar, const Vector3& InVector)
{
	return { Scalar * InVector.x, Scalar * InVector.y, Scalar * InVector.z };
}

float& operator*=(float& Scalar, const Vector3& InVector)
{
	Scalar *= InVector.Length();
	return Scalar;
}

std::ostream& operator<<(std::ostream& OutOstream, const Vector3& vector)
{
		OutOstream << vector.ToString();
		return OutOstream;
}
