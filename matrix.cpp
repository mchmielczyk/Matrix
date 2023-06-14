#include "matrix.h"
template<typename T>
Matrix<T>::Matrix() : rows(0), cols(0), tab(nullptr) {}
template<typename T>
Matrix<T>::Matrix(int rows_, int cols_) : rows(rows_), cols(cols_) {
    tab = new T * [rows];
    for (int i = 0; i < rows; i++) {
        tab[i] = new T[cols];
        for (int j = 0; j < cols; j++) {
            tab[i][j] = 0;
        }
    }
}
template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] tab[i];
    }
    delete[] tab;
}
template<typename T>
template<typename C>
void Matrix<T>::operator=(const Matrix<C>& M2) {
    if (cols != M2.cols || rows != M2.rows) {
        std::cout << "Rozmiary macierzy nie są takie same!" << std::endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tab[i][j] = static_cast<T>(M2.tab[i][j]);
        }
    }
}

template<typename T, typename C>
bool operator==(const Matrix<T>& M1, const Matrix<C>& M2) {
    if (M1.cols != M2.cols || M1.rows != M2.rows) {
        std::cout << "Rozmiary macierzy nie są takie same!" << std::endl;
        return false;
    }
    bool flag = true;
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M1.cols; j++) {
            if (M1.tab[i][j] != M2.tab[i][j])
                flag = false;
        }
    }
    return flag;
}

template<typename T>
T* Matrix<T>::operator[](int row) {
    return tab[row];
}

template<typename T, typename C>
Matrix<T> operator+(const Matrix<T>& M1, const Matrix<C>& M2) {
    if (M1.cols != M2.cols || M1.rows != M2.rows) {
        std::cout << "Rozmiary macierzy nie są takie same!" << std::endl;
        return Matrix<T>();
    }
    Matrix<T> res(M1.rows, M1.cols);
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M1.cols; j++) {
            res.tab[i][j] = M1.tab[i][j] + static_cast<T>(M2.tab[i][j]);
        }
    }
    return res;
}

template<typename T, typename C>
Matrix<T> operator-(const Matrix<T>& M1, const Matrix<C>& M2) {
    if (M1.cols != M2.cols || M1.rows != M2.rows) {
        std::cout << "Rozmiary macierzy nie są takie same!" << std::endl;
        return Matrix<T>();
    }
    Matrix<T> res(M1.rows, M1.cols);
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M1.cols; j++) {
            res.tab[i][j] = M1.tab[i][j] - static_cast<T>(M2.tab[i][j]);
        }
    }
    return res;
}

template<typename T, typename C>
Matrix<T> operator*(const Matrix<T>& M1, const Matrix<C>& M2) {
    if (M1.cols != M2.rows) {
        std::cout << "Rozmiary macierzy nie są zgodne!" << std::endl;
        return Matrix<T>();
    }
    Matrix<T> res(M1.rows, M2.cols);
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

template<typename T>
Matrix<T> Matrix<T>::operator*(int scalar) {
    Matrix<T> res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res.tab[i][j] = tab[i][j] * scalar;
        }
    }
    return res;
}
template<typename C>
std::ostream& operator<<(std::ostream& os, const Matrix<C>& M) {
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            os << M.tab[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

template<typename T>
Matrix<T> Transpose(const Matrix<T>& M) {
    Matrix<T> res(M.cols, M.rows);
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            res.tab[j][i] = M.tab[i][j];
        }
    }
    return res;
}

template<typename T>
Matrix<T> Inverse(Matrix<T>& M)
{
    Matrix<T> tmp(M.rows, M.cols);
    for (int i = 0; i < M.rows; i++)
    {
        for (int j = 0; j < M.cols; j++)
        {
            if (M.tab[i][j] < 0)
                tmp[j][i] = -M.tab[i][j];
            else
                tmp[j][i] = M.tab[i][j];
        }
    }
    return tmp;
}