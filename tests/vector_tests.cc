#include "../include/functions/vector_functions.h"

#include <gtest/gtest.h>
#include <complex>
using namespace vlad;




template <typename T>
T triangle_square(Vector<T> first_vector, Vector<T> second_vector) {
    Vector<T> third_vector = first_vector - second_vector;

    T a = first_vector.vector_length();
    T b = second_vector.vector_length();
    T c = third_vector.vector_length();
    T p = (a + b + c) / 2;
    return sqrt((p * (p - a) * (p - b) * (p - c)));
}



TEST(FunctionsTests, OperatorIndex) {
    float a[2] = { 1.5, 0 };
    Vector<float> testor(2, a);
    EXPECT_TRUE(testor[0] == 1.5);
}

TEST(FunctionsTests, OperatorEqual) {
    float a[2] = { 1.5, 0 };
    Vector<float> testor1(2, a);

    float b[2] = { 1.5, 10 };
    Vector<float> testor2(2, b);

    EXPECT_FALSE(testor1 == testor2);
}

TEST(FunctionsTests, OperatorPlus) {
    float a[2] = { 1.5, 0 };
    Vector<float> testor1(2, a);

    float b[2] = { 1.5, 10 };
    Vector<float> testor2(2, b);

    Vector<float> testor3 = testor1 + testor2;

    float c[2] = { 3, 10 };
    Vector<float> result(2, c);
    EXPECT_TRUE(testor3 == result);
}


TEST(FunctionsTests, OperatorComplexPlus) {
    std::complex<float> a1(2, 1);
    std::complex<float> a2(4, 2);
    std::complex<float> a[] = {a1, a2};
    
    Vector testor1(2, a);

    std::complex<float> b1(3, 3);
    std::complex<float> b2(4, 4);
    std::complex<float> b[] = { b1, b2 };

    Vector testor2(2, b);

    Vector testor3 = testor1 + testor2;


    std::complex<float> c1(5, 4);
    std::complex<float> c2(8, 6);
    std::complex<float> c[] = { c1, c2 };
    Vector result(2, c);
    EXPECT_TRUE(testor3 == result);
}




TEST(FunctionsTests, OperatorMinus) {
    float a[2] = { 1.5, 0 };
    Vector<float> testor1(2, a);

    float b[2] = { 1.5, 10 };
    Vector<float> testor2(2, b);

    Vector<float> testor3 = testor1 - testor2;

    float c[2] = { 0, -10 };
    Vector<float> result(2, c);
    EXPECT_TRUE(testor3 == result);
}

TEST(FunctionsTests, OperatorMultiply) {
    float a[2] = { 1.5, 0 };
    Vector<float> testor1(2, a);

    float b[2] = { 1.5, 10 };
    Vector<float> testor2(2, b);

    Vector<float> testor3 = testor1 * testor2;

    float c[2] = { 2.25, 0 };
    Vector<float> result(2, c);
    EXPECT_TRUE(testor3 == result);
}


TEST(FunctionsTests, OperatorComplexMultiply) {
    std::complex<float> a1(2, 1);
    std::complex<float> a2(4, 2);
    std::complex<float> a[] = { a1, a2 };

    Vector testor1(2, a);

    std::complex<float> b1(3, 3);
    std::complex<float> b2(4, 4);
    std::complex<float> b[] = { b1, b2 };

    Vector testor2(2, b);

    Vector testor3 = testor1 * testor2;


    std::complex<float> c1(9, -3);
    std::complex<float> c2(24, -8);
    std::complex<float> c[] = { c1, c2 };
    Vector result(2, c);
    EXPECT_TRUE(testor3 == result);
}

TEST(FunctionsTests, OperatorMultiplyByNumber) {
    float a[2] = { 1.5 , 0 };
    Vector<float> testor(2, a);

    Vector<float> testor3 = testor * 2;

    float c[2] = { 3, 0 };
    Vector<float> result(2, c);
    EXPECT_TRUE(testor3 == result);
}

TEST(FunctionsTests, OperatorDivide) {
    float a[2] = { 1.5, 0 };
    Vector<float> testor(2, a);

    Vector<float> testor3 = testor / 3;

    float c[2] = { 0.5, 0 };
    Vector<float> result(2, c);
    EXPECT_TRUE(testor3 == result);
}

TEST(FunctionsTests, OperatorMultiplyIsCommutative) {
    float a[2] = { 1.5, 0 };
    Vector<float> testor(2, a);
    EXPECT_TRUE(testor[0] == 1.5);
}

TEST(FunctionsTests, TriangleSquare) {
    float a[2] = { 0, 2 };
    Vector<float> testor1(2, a);

    float b[2] = { 4, 0 };
    Vector<float> testor2(2, b);

    float result = triangle_square(testor1, testor2);
    EXPECT_NEAR(result, 4, 0.001);
}

TEST(FunctionsTests, OperatorIndexError) {
    float a[2] = { 1.5, 0 };
    Vector<float> testor(2, a);
    EXPECT_THROW(testor[4] == 1.5, std::out_of_range);
}