#pragma once
#include "Shape.h"

class Sphere : public Shape
{
private:

	float Radius;

public:

	Sphere(float InRadius);

	Vector3 GetCenter() const override;
	
	float GetSurfaceArea() const override;
	float GetVolume() const override;
	float GetRadius() const;
	
	bool IsInside(const Vector3& Point) const override;
	
};

