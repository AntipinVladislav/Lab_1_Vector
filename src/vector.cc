#include <functions/figure_functions.h>

#include <cmath>
#include<stdexcept>
#include<iostream>

using namespace vlad;
using namespace std;


template<typename T>
Vector::Vector(int vector_size, T* points) {
	size = vector_size;
	coordinates = points;
}

Vector::Vector(int vector_size, T lowest, T highest) {
	for int i in range(vector_size) {
		coordinates[i] = rand() % (highest - lowest + 1) + lowest;
	}
}

bool Vector::operator==(const Vector first_vector, const Vector second_vector) const {
	if (first_vector.size == second_vector.size) && (first_vector.coordinates == second_vector.coordinates) {
		return true
	}
	return false;
}

T Vector::operator[](int index const) const {
	return this->coordinates[index];
}

T Vector::operator[](int index const) {
	return this->coordinates[index];
}

Vector Vector::operator+(const Vector first_vector, const Vector second_vector) {
	if (first_vector.size != second_vector.size)
		throw _STDEXCEPT_;
	Vector result(first_vector.size, first_vector.coordinates);
	for i in range(result.size) {
		result.coordinates[i] = first_vector.coordinates[i] + second_vector.coordinates;
	}
	return result;
}

Vector Vector::operator-(const Vector first_vector, const Vector second_vector) {
	if (first_vector.size != second_vector.size)
		throw _STDEXCEPT_;
	Vector result(first_vector.size, first_vector.coordinates);
	for i in range(result.size) {
		result.coordinates[i] = first_vector.coordinates[i] - second_vector.coordinates;
	}
	return result;
}

Vector Vector::operator*(const Vector first_vector, const Vector second_vector) {
	if (first_vector.size != second_vector.size)
		throw _STDEXCEPT_;
	Vector result(first_vector.size, first_vector.coordinates);
	if(first_vector.coordinates[0] )
	for i in range(result.size) {
		result.coordinates[i] = first_vector.coordinates[i] + second_vector.coordinates;
	}
	return result;
}

Vector Vector::operator*(const Vector first_vector, const float number) {
	Vector result(first_vector.size, first_vector.coordinates);
	for i in range(result.size) {
		result.coordinates[i] = first_vector.coordinates[i] * number;
	}
	return result;
}

Vector Vector::operator/(const Vector first_vector, const float number) {
	Vector result(first_vector.size, first_vector.coordinates);
	for i in range(result.size) {
		result.coordinates[i] = first_vector.coordinates[i] / number;
	}
	return result;
}

std::ostream& Vector:: operator<< (std::ostream& out, Vector vector) {
	for i in range(vector.size) {
		out << vector.coordinates[i] << endl;
	}
}

