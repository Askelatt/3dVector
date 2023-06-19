#include "Capsule.h"

Capsule::Capsule(float InLength, const Vector3& InOrientation, float InRadius)
	: Length(InLength), Orientation(InOrientation.GetNormalized()), Radius(InRadius) {}

Vector3 Capsule::GetCenter() const
{
	return Center;
}

Vector3 Capsule::GetOrientation() const
{
	return Orientation;
}

float Capsule::GetSurfaceArea() const
{
	float SphereSurfaceArea = 4.0f * M_PI * Radius * Radius;
	float CylinderSurfaceArea = 2.0f * M_PI * Radius * Length;
	return SphereSurfaceArea + CylinderSurfaceArea;
}

float Capsule::GetVolume() const
{
	float SphereVolume = (4.0f / 3.0f) * M_PI * Radius * Radius * Radius;
	float CylinderVolume = M_PI * Radius * Radius * Length;
	return SphereVolume + CylinderVolume;
}

float Capsule::GetLength() const
{
	return Length;
}

float Capsule::GetRadius() const
{
	return Radius;
}

bool Capsule::IsInside(const Vector3& Point) const
{
	Vector3 PointToCenter = Point - Center;

	float Projection = Vector3::DotProduct(PointToCenter, Orientation);

	Vector3 ClosestPointOnAxis = Center + (Orientation * Projection);

	float AxisLength = Length * 0.5f;

	if (Projection < -AxisLength || Projection > AxisLength)
	{
		return false;  // The closest point on the capsule axis is beyond the length of the capsule.
	}

	float Distance = Vector3::Distance(Point, ClosestPointOnAxis);

	// Check that point is inside Capsule
	return Distance <= Radius;
}
