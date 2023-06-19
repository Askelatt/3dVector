#pragma once
#include <stdexcept>
#include <iomanip>
#include <sstream>

template<typename T>
class Vector
{
	static_assert(std::is_arithmetic<T>::value, "Vector template requires a numeric type");
private:

	T* Data;
	size_t Size;

public:

	Vector(size_t InSize = 4) : Size(InSize)
	{
		Data = new T[Size];
		for (size_t i = 0; i < Size; ++i)
		{
			Data[i] = 0;
		}
	}

	~Vector()
	{
		delete[] Data;
	}

	//Copy constructor
	Vector(const Vector& InVector) : Size(InVector.Size)
	{
		Data = new T[Size];
		std::copy(InVector.Data, InVector.Data + Size, Data);
	}

	// copy assignment
	Vector& operator=(const Vector& InVector)
	{
		if (this == &InVector)
		{
			return *this; 
		}

		delete[] Data;
		Size = InVector.Size;
		Data = new T[Size];
		std::copy(InVector.Data, InVector.Data + Size, Data);

		return *this;
	}

	// move constructor
	Vector(Vector&& InVector) noexcept : Data(InVector.Data), Size(InVector.Size)
	{
		InVector.Data = nullptr;
		InVector.Size = 0;
	}

	Vector(T Count) : Size(Count)
	{
		Data = new T[Size];
		for (size_t i = 0; i < Size; ++i)
		{
			Data[i] = 0;
		}
	}

	Vector(int Count, T DefaultValue) : Size(Count)
	{
		Data = new T[Size];
		for (size_t i = 0; i < Size; ++i)
		{
			Data[i] = DefaultValue;
		}
	}
	//move assignment operator
	Vector& operator=(Vector&& InVector) noexcept
	{
		if (this == &InVector)
		{
			return *this; 
		}

		delete[] Data;
		Size = InVector.Size;
		Data = InVector.Data;
		InVector.Size = 0;
		InVector.Data = nullptr;

		return *this;
	}

	// Index operator
	T& operator[](size_t Index) 
	{
		if (Index >= Size)
		{
			throw std::out_of_range("Vector index out of bounds");
		}
		return Data[Index];
	}

	// Constant indexing operator
	const T& operator[](size_t Index) const
	{
		if (Index >= Size)
		{
			throw std::out_of_range("Vector index out of bounds");
		}
		return Data[Index];
	}

	size_t GetSize() const
	{
		return Size;
	}

	static Vector ZeroVector(int Count)
	{
		return Vector(Count, 0);
	}

	static Vector OneVector(int Count)
	{
		return Vector(Count, 1);
	}

	std::string ToString() const
	{
		std::ostringstream SS;
		SS << std::fixed << std::setprecision(3) << "<";
		for (size_t i = 0; i < Size; ++i)
		{
			SS << Data[i];
			if (i != Size - 1)
			{
				SS << ", ";
			}
		}
		SS << ">";
		return SS.str();
	}

	friend std::ostream& operator<<(std::ostream& OutOstream, const Vector& InVector)
	{
		OutOstream << InVector.ToString();
		return OutOstream;
	} 

};

