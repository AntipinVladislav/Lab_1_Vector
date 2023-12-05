#pragma once
#include <iostream>

namespace vlad {
	template<typename T>
	class Vector<T>{
	private:
		int size;
		T* coordinates;
	public:
		Vector(int vector_size, T* points);
		Vector(str random);
		T operator[](int index const) const;
		T operator[](int index const);
		Vector operator+(const Vector first_vector, const Vector second_vector);
		Vector operator-(const Vector first_vector, const Vector second_vector);
		Vector operator*(const Vector first_vector, const Vector second_vector);
		Vector operator*(const Vector first_vector, const float);
		Vector operator/(const Vector first_vector, const float number);

		std::ostream& operator<< (std::ostream& out, Vector vector);
	
	}

