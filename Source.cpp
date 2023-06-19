#include <iostream>
#include "Vector.h"
#include "Vector3.h"

int main()
{
	Vector3 v1;
	Vector3 v2(5.f);
	Vector3 v3(10.f, 20.f, -30.f);
	std::vector<float> coords = { 50.f, 0.f, -5.f };
	Vector3 v4(coords);

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v4: " << v4 << std::endl;

	Vector3 zeroVec = Vector3::ZeroVector();
	Vector3 oneVec = Vector3::OneVector();
	Vector3 upVec = Vector3::UpVector();

	std::cout << "ZeroVector : " << zeroVec << std::endl;
	std::cout << "OneVector : " << oneVec << std::endl;
	std::cout << "UpVector : " << upVec << std::endl;

	Vector<int> IntVector(12);

	Vector<int> IntVector2 = IntVector;

	Vector<float> FloatVector(13.f);

	Vector<float> FixedVector(10, 15.f);

	std::cout << "Fixed is " << FixedVector << std::endl;
	std::cout << Vector<float>::ZeroVector(10);

	return 0;
}

