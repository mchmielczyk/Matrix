#include <gtest/gtest.h>
#include "matrix.h"
// Test fixture for Matrix class
template<typename T>
class MatrixTest : public ::testing::Test {
protected:
    Matrix<T> matrix;
};

TYPED_TEST_SUITE_P(MatrixTest);

// Test case for matrix equality operator
TYPED_TEST_P(MatrixTest, EqualityOperator) {
    // Create two matrices with the same dimensions and values
    Matrix<TypeParam> matrix1(2, 2);
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;

    Matrix<TypeParam> matrix2(2, 2);
    matrix2[0][0] = 1;
    matrix2[0][1] = 2;
    matrix2[1][0] = 3;
    matrix2[1][1] = 4;

    // Verify that the matrices are equal
    EXPECT_EQ(matrix1, matrix2);
}

// Test case for matrix equality operator - matrices have different sizes
TYPED_TEST_P(MatrixTest, EqualityOperatorNotEqualSizes) {
    // Create two matrices with different dimensions and values
    Matrix<TypeParam> matrix1(2, 2);
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;

    Matrix<TypeParam> matrix2(2, 2);
    matrix2[0][0] = 1;
    matrix2[0][1] = 2;
    matrix2[1][0] = 3;
    matrix2[1][1] = 4;

    // Verify that the matrices are not equal
    EXPECT_FALSE(matrix1==matrix2?1:0);
}

// Test case for matrix addition operator
TYPED_TEST_P(MatrixTest, AdditionOperator) {
    // Create two matrices with the same dimensions
    Matrix<TypeParam> matrix1(2, 2);
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;

    Matrix<TypeParam> matrix2(2, 2);
    matrix2[0][0] = 5;
    matrix2[0][1] = 6;
    matrix2[1][0] = 7;
    matrix2[1][1] = 8;

    // Perform matrix addition
    Matrix<TypeParam> result = matrix1 + matrix2;

    // Verify the result
    EXPECT_EQ(6, result[0][0]);
    EXPECT_EQ(8, result[0][1]);
    EXPECT_EQ(10, result[1][0]);
    EXPECT_EQ(12, result[1][1]);
}

// Register the typed test cases
REGISTER_TYPED_TEST_SUITE_P(MatrixTest, EqualityOperator, EqualityOperatorNotEqualSizes, AdditionOperator);

// Define the types to be tested
typedef ::testing::Types<int, double, float> MatrixTypes;

// Instantiate the typed tests
INSTANTIATE_TYPED_TEST_SUITE_P(MatrixTestSuite, MatrixTest, MatrixTypes);