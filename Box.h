#pragma once
#include "Shape.h"

class Box : public Shape
{
private:

	Vector3 Min;

	Vector3 Max;

public:

	Box(const Vector3& MinPoint, const Vector3& MaxPoint);
	
	//Accessors
	Vector3 GetCenter() const override;
	Vector3 GetSize();
	
	float GetSurfaceArea() const override;
	float GetVolume() const override;
	
	std::vector<Vector3> GetVertices() const;

	//Functions
	bool IsInside(const Vector3& Point) const override;

};

