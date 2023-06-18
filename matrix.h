#ifndef _Matrix
#define _Matrix

#include <iostream>

// Forward declarations
template<typename T>
class Matrix;
template<typename T, typename C>
bool operator==(const Matrix<T>& M1, const Matrix<C>& M2);
template<typename T, typename C>
Matrix<T> operator+(const Matrix<T>& M1, const Matrix<C>& M2);
template<typename T, typename C>
Matrix<T> operator-(const Matrix<T>& M1, const Matrix<C>& M2);
template<typename T, typename C>
Matrix<T> operator*(const Matrix<T>& M1, const Matrix<C>& M2);
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& M);
template<typename T>
Matrix<T> Transpose(Matrix<T>& M);
template<typename T>
Matrix<T> Inverse(Matrix<T>& M);

// Matrix class definition
template<typename T>
class Matrix
{
private:
    int rows;   // Number of rows in the matrix
    int cols;   // Number of columns in the matrix
    T** tab;    // Pointer to a 2D array representing the matrix

public:
    Matrix();   // Default constructor
    Matrix(int rows_, int cols_);   // Parameterized constructor
    ~Matrix();  // Destructor

    // Copy assignment operator overload
    template<typename C>
    void operator=(const Matrix<C>& M2);

    // Friend function declarations
    friend bool operator==<>(const Matrix& M1, const Matrix& M2);
    friend Matrix operator+<>(const Matrix& M1, const Matrix& M2);
    friend Matrix operator-<>(const Matrix& M1, const Matrix& M2);
    friend Matrix operator*<>(const Matrix& M1, const Matrix& M2);
    friend Matrix Transpose<T>(Matrix& M);
    friend Matrix Inverse<T>(Matrix& M);

    T* operator[](int num);  // Array subscript operator overload
    Matrix<T> operator*(int scalar);    // Scalar multiplication operator overload
    friend std::ostream& operator<<<T>(std::ostream& os, Matrix& M);    // Output stream operator overload
};

// Default constructor implementation
template<typename T>
Matrix<T>::Matrix() : rows(0), cols(0), tab(nullptr) {}

// Parameterized constructor implementation
template<typename T>
Matrix<T>::Matrix(int rows_, int cols_) : rows(rows_), cols(cols_) {
    // Dynamically allocate memory for the matrix elements
    tab = new T * [rows];
    for (int i = 0; i < rows; i++) {
        tab[i] = new T[cols];
        // Initialize matrix elements to zero
        for (int j = 0; j < cols; j++) {
            tab[i][j] = 0;
        }
    }
}

// Destructor implementation
template<typename T>
Matrix<T>::~Matrix() {
    // Deallocate the dynamically allocated memory for the matrix elements
    for (int i = 0; i < rows; i++) {
        delete[] tab[i];
    }
    delete[] tab;
}

// Copy assignment operator overload implementation
template<typename T>
template<typename C>
void Matrix<T>::operator=(const Matrix<C>& M2) {
    // Check if the matrices have the same dimensions
    if (cols != M2.cols || rows != M2.rows) {
        std::cout << "Matrices sizes are not the same!" << std::endl;
        return;
    }

    // Copy the elements from the source matrix to the current matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tab[i][j] = static_cast<T>(M2.tab[i][j]);
        }
    }
}

// Friend function for equality comparison operator overload
template<typename T, typename C>
bool operator==(const Matrix<T>& M1, const Matrix<C>& M2) {
    // Check if the matrices have the same dimensions
    if (M1.cols != M2.cols || M1.rows != M2.rows) {
        std::cout << "Matrices sizes are not the same!" << std::endl;
        return false;
    }

    bool flag = true;

    // Compare the elements of the matrices
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M1.cols; j++) {
            if (M1.tab[i][j] != M2.tab[i][j])
                flag = false;
        }
    }

    return flag;
}

// Array subscript operator overload implementation
template<typename T>
T* Matrix<T>::operator[](int row) {
    return tab[row];
}

// Friend function for matrix addition operator overload
template<typename T, typename C>
Matrix<T> operator+(const Matrix<T>& M1, const Matrix<C>& M2) {
    // Check if the matrices have the same dimensions
    if (M1.cols != M2.cols || M1.rows != M2.rows) {
        std::cout << "Matrices sizes are not the same!" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> res(M1.rows, M1.cols);

    // Perform element-wise addition
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M1.cols; j++) {
            res.tab[i][j] = M1.tab[i][j] + static_cast<T>(M2.tab[i][j]);
        }
    }

    return res;
}

// Friend function for matrix subtraction operator overload
template<typename T, typename C>
Matrix<T> operator-(const Matrix<T>& M1, const Matrix<C>& M2) {
    // Check if the matrices have the same dimensions
    if (M1.cols != M2.cols || M1.rows != M2.rows) {
        std::cout << "Matrices sizes are not the same!" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> res(M1.rows, M1.cols);

    // Perform element-wise subtraction
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M1.cols; j++) {
            res.tab[i][j] = M1.tab[i][j] - static_cast<T>(M2.tab[i][j]);
        }
    }

    return res;
}

// Friend function for matrix multiplication operator overload
template<typename T, typename C>
Matrix<T> operator*(const Matrix<T>& M1, const Matrix<C>& M2) {
    // Check if the matrices have compatible dimensions for multiplication
    if (M1.cols != M2.rows) {
        std::cout << "Matrices sizes are not the same!" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> res(M1.rows, M2.cols);

    // Perform matrix multiplication
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M2.cols; j++) {
            res.tab[i][j] = static_cast<T>(0);
            for (int k = 0; k < M1.cols; k++) {
                res.tab[i][j] += M1.tab[i][k] * static_cast<T>(M2.tab[k][j]);
            }
        }
    }

    return res;
}

// Scalar multiplication operator overload implementation
template<typename T>
Matrix<T> Matrix<T>::operator*(int scalar) {
    Matrix<T> res(rows, cols);

    // Perform scalar multiplication
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res.tab[i][j] = tab[i][j] * scalar;
        }
    }

    return res;
}

// Output stream operator overload implementation
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& M) {
    // Print the matrix elements
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            os << M.tab[i][j] << " ";
        }
        os << std::endl;
    }

    return os;
}

// Transpose function implementation
template<typename T>
Matrix<T> Transpose(Matrix<T>& M) {
    Matrix<T> res(M.cols, M.rows);

    // Transpose the matrix
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            res.tab[j][i] = M.tab[i][j];
        }
    }

    return res;
}

// Inverse function implementation
template<typename T>
Matrix<T> Inverse(Matrix<T>& M) {
    Matrix<T> tmp(M.rows, M.cols);

    // Compute the absolute values of the matrix elements
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            if (M.tab[i][j] < 0)
                tmp[j][i] = -M.tab[i][j];
            else
                tmp[j][i] = M.tab[i][j];
        }
    }

    return tmp;
}

#endif // !_Matrix