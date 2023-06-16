#include "matrix.h"
#include <iostream>
#include <cassert>

int main() {
    // Test matrix creation and indexing
    Matrix<int> m1(2, 2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 4;
    m1[1][1] = 5;
    assert(m1[0][0] == 1);
    assert(m1[0][1] == 2);
    assert(m1[1][0] == 4);
    assert(m1[1][1] == 5);

    // Test matrix equality
    Matrix<int> m2 = m1;
    assert(m1 == m2);

    // Test matrix addition
    Matrix<int> m3 = m1 + m2;
    Matrix<int> expectedAddition(2, 2);
    expectedAddition[0][0] = 2;
    expectedAddition[0][1] = 4;
    expectedAddition[1][0] = 8;
    expectedAddition[1][1] = 10;
    assert(m3 == expectedAddition);

    // Test matrix multiplication
    Matrix<int> m4(2, 2);
    m4[0][0] = 1;
    m4[0][1] = 2;
    m4[1][0] = 3;
    m4[1][1] = 4;
    Matrix<int> m5 = m1 * m4;
    Matrix<int> expectedMultiplication(2, 2);
    expectedMultiplication[0][0] = 7;
    expectedMultiplication[0][1] = 10;
    expectedMultiplication[1][0] = 19;
    expectedMultiplication[1][1] = 28;
    assert(m5 == expectedMultiplication);

    // Test matrix scalar multiplication
    Matrix<int> m6 = m1 * 2;
    Matrix<int> expectedScalarMultiplication(2, 2);
    expectedScalarMultiplication[0][0] = 2;
    expectedScalarMultiplication[0][1] = 4;
    expectedScalarMultiplication[1][0] = 8;
    expectedScalarMultiplication[1][1] = 10;
    assert(m6 == expectedScalarMultiplication);

    // Test matrix transposition
    Matrix<int> m7 = Transpose(m1);
    Matrix<int> expectedTranspose(2, 2);
    expectedTranspose[0][0] = 1;
    expectedTranspose[0][1] = 4;
    expectedTranspose[1][0] = 2;
    expectedTranspose[1][1] = 5;
    assert(m7 == expectedTranspose);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}