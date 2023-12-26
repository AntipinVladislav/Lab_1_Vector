#include "../include/functions/vector_functions.h"

#include <cmath>
#include <complex>
#include <stdexcept>

using namespace vlad;
using namespace std;

template class vlad::Vector<int>;
template class vlad::Vector<float>;
template class vlad::Vector<double>;
template class vlad::Vector<std::complex<float>>;
template class vlad::Vector<std::complex<double>>;

template <typename T>
Vector<T>::Vector(const int vector_size, T* points) {
	size = vector_size;
	coordinates = points;
}

template <typename T>
Vector<T>::Vector(const int vector_size, T lowest, T highest) {
	coordinates = new T[vector_size];
	size = vector_size;
	std::mt19937 random_engine(random_device());

	if constexpr (std::is_same_v<T, std::complex<float>>)
	{
		std::uniform_real_distribution<> real_dist(lowest.real(), highest.real());
		std::uniform_real_distribution<> imag_dist(lowest.imag(), highest.imag());

		for (int i = 0; i < vector_size; i++) {
			coordinates[i] = std::complex<float>(real_dist(random_engine), imag_dist(random_engine));
		}
	}

	else if constexpr (std::is_same_v<T, std::complex<double>>)
	{
		std::uniform_real_distribution<> real_dist(lowest.real(), highest.real());
		std::uniform_real_distribution<> imag_dist(lowest.imag(), highest.imag());
		for (int i = 0; i < vector_size; i++) {
			coordinates[i] = std::complex<double>(real_dist(random_engine), imag_dist(random_engine));
		}
	}
    else
	{
		std::uniform_int_distribution<> dist(lowest, highest);
		for (int i = 0; i < vector_size; i++) {
			coordinates[i] = dist(random_engine);
		}
	}
}

template <typename T>
bool Vector<T>::operator==(Vector second_vector) const
{
	if (size == second_vector.size) {
		for (int i = 0; i < size; i++)
		{
			if (coordinates[i] != second_vector.coordinates[i])
				return false;
		}

		return true;
	}
	return false;
}

template <typename T>
T Vector<T>::operator[](const int index) {
	if (index > size) {
		throw out_of_range("index out of range");
	}
	return this->coordinates[index];
}

template <typename T>
const T Vector<T>::operator[](const int index) const{
	if (index > size) {
		throw out_of_range("index out of range");
	}
	return this->coordinates[index];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector second_vector) {
	if (size != second_vector.size)
		throw invalid_argument("sizes are not equal");
	Vector result(size, new T[size]);
	for (int i = 0; i < result.size; i++) {
		result.coordinates[i] = coordinates[i] + second_vector.coordinates[i];
	}
	return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector second_vector) {
	if (size != second_vector.size)
		throw invalid_argument("sizes are not equal");
	Vector result(size, new T[size]);
	for (int i = 0; i < result.size; i++) {
		result.coordinates[i] = coordinates[i] - second_vector.coordinates[i];
	}
	return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const Vector second_vector) {
	if (size != second_vector.size)
		throw invalid_argument("sizes are not equal");
	Vector result(size, new T[size]);

	if constexpr (std::is_same_v<T, std::complex<float>>)
	{

		for (int i = 0; i < size; i++) {
			result.coordinates[i] = coordinates[i] * conj(second_vector.coordinates[i]);
		}
	}

	else if constexpr (std::is_same_v<T, std::complex<double>>)
	{
		for (int i = 0; i < size; i++) {
			result.coordinates[i] = coordinates[i] * conj(second_vector.coordinates[i]);
		}
	}
	else{
		for (int i = 0; i < result.size; i++) {
			result.coordinates[i] = coordinates[i] * second_vector.coordinates[i];
		}
	}
	return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const float number) {
	Vector result(size, new T[size]);
	for (int i = 0; i < result.size; i++) {
		if constexpr (std::is_same_v<T, std::complex<float>>)
		{
			coordinates[i] = std::complex<float>(coordinates[i].real() * number, coordinates[i].imag() * number);
		}
		else if constexpr (std::is_same_v<T, std::complex<double>>)
		{
			coordinates[i] = std::complex<double>(coordinates[i].real() * number, coordinates[i].imag() * number);
		}
		else
		{
			result.coordinates[i] = coordinates[i] * number;
		}
	}
	return result;
}

template <typename T>
Vector<T> operator*(const float& number, const Vector<T> first_vector) {
	return first_vector * number;
}

template <typename T>
Vector<T> Vector<T>::operator/(const float number) {
	Vector result(size, new T[size]);
	for (int i = 0; i < result.size; i++) {
		if constexpr (std::is_same_v<T, std::complex<float>>)
		{
		    coordinates[i] = std::complex<float>(coordinates[i].real() / number, coordinates[i].imag() / number);
		}
		else if constexpr (std::is_same_v<T, std::complex<double>>)
		{
			coordinates[i] = std::complex<double>(coordinates[i].real() / number, coordinates[i].imag() / number);
		}
		else
		{
			result.coordinates[i] = coordinates[i] / number;
		}
	}
	return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Vector<T> vector) {
	for (int i = 0; i < vector.size; i++) {
		out << vector.coordinates[i] << endl;
	}
	return out;
}

template <typename T>
T Vector<T>:: vector_length() {
	T result{0};
	for (int i = 0; i < size; i++) {
		result += coordinates[i] * coordinates[i];
	}
	return sqrt(abs(result));
}