#pragma once

#include <iostream>
#include <random>

namespace vlad {
	template<typename T>
	class Vector {
	private:
		int size;
		T* coordinates;
	public:
		Vector(int vector_size, T* points);
		Vector(int vector_size, T lowest, T highest);

		T operator[](int index);

		bool operator==(Vector second_vector) const;

		Vector operator+(Vector second_vector);
		Vector operator-(Vector second_vector);
		Vector operator*(Vector second_vector);

		Vector operator*(float number);
		friend Vector operator*(float& number, Vector first_vector);

		Vector operator/(float number);

		T vector_length();

		friend std::ostream& operator<<(std::ostream& out, Vector vector);

		inline static std::random_device random_device{};
	};

	//template <typename T>
	//T triangle_square(Vector<T> first_vector, Vector<T> second_vector) {
	//	Vector<T> third_vector = first_vector - second_vector;
	//	T a = sqrt(first_vector * first_vector);
	//	T b = sqrt(second_vector * second_vector);
	//	T c = sqrt(third_vector * third_vector);
	//	T p = (a + b + c) / 2;
	//	return sqrt(p * (p - a) * (p - b) * (p - c));
	//}
}
