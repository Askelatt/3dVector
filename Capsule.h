#pragma once
#include "Shape.h"

class Capsule : public Shape
{
private:

	float Length;

	float Radius;

	Vector3 Orientation;

public:

	Capsule(float InLength, const Vector3& InOrientation, float InRadius);
		
	Vector3 GetCenter() const override;
	Vector3 GetOrientation() const;
	
	float GetSurfaceArea() const override;
	float GetVolume() const;
	float GetLength() const;
	float GetRadius() const;
	
	bool IsInside(const Vector3& Point) const override;
	
};

