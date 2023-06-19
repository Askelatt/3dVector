#include "Box.h"

Box::Box(const Vector3& MinPoint, const Vector3& MaxPoint)
	: Min(MinPoint), Max(MaxPoint) {}

Vector3 Box::GetCenter() const
{
	return (Min + Max) * 0.5f;
}

Vector3 Box::GetSize()
{
	return Max - Min;
}

float Box::GetSurfaceArea() const
{
	float Width = Max.x - Min.x;
	float Height = Max.y - Min.y;
	float Depth = Max.z - Min.z;
	return 2.0f * (Width * Height + Height * Depth + Depth * Width); //S = 2(a · b + a · h + b · h) 
}

float Box::GetVolume() const
{
	float Width = Max.x - Min.x;
	float Height = Max.y - Min.y;
	float Depth = Max.z - Min.z;
	return Width * Height * Depth;
}

bool Box::IsInside(const Vector3& Point) const
{
	return  Point.x >= Min.x && Point.x <= Max.x &&
		Point.y >= Min.y && Point.y <= Max.y &&
		Point.z >= Min.z && Point.z <= Max.z;
}

std::vector<Vector3> Box::GetVertices() const
{
	std::vector<Vector3> Vertices;
	Vertices.push_back(Vector3(Min.x, Min.y, Min.z));
	Vertices.push_back(Vector3(Min.x, Min.y, Max.z));
	Vertices.push_back(Vector3(Min.x, Max.y, Min.z));
	Vertices.push_back(Vector3(Min.x, Max.y, Max.z));
	Vertices.push_back(Vector3(Max.x, Min.y, Min.z));
	Vertices.push_back(Vector3(Max.x, Min.y, Max.z));
	Vertices.push_back(Vector3(Max.x, Max.y, Min.z));
	Vertices.push_back(Vector3(Max.x, Max.y, Max.z));
	return Vertices;
}