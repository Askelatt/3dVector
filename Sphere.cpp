#include "Sphere.h"

Sphere::Sphere(float InRadius) : Radius(InRadius) {}

Vector3 Sphere::GetCenter() const
{
	return Center;
}

float Sphere::GetSurfaceArea() const
{
	return 4.0f * M_PI * Radius * Radius;
}

float Sphere::GetVolume() const
{
	return (4.0f / 3.0f) * M_PI * Radius * Radius * Radius;
}

float Sphere::GetRadius() const
{
	return Radius;
}

bool Sphere::IsInside(const Vector3& Point) const
{
	// Calculate the distance between the point and the center of the sphere
	float Distance = Vector3::Distance(Center, Point);
	return Distance <= Radius;
}
