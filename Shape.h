#pragma once
#include "Vector3.h"

class Shape
{
public:
	Vector3 Center;

	virtual Vector3 GetCenter() const = 0;

	virtual float GetSurfaceArea() const = 0;

	virtual float GetVolume() const = 0;

	virtual bool IsInside(const Vector3& point) const = 0;
};
