#ifndef _Matrix
#define _Matrix
#include <iostream>
template<typename T>
class Matrix
{
private:
	int rows;
	int cols;
	T** tab;
public:
	Matrix();
	Matrix(int rows_, int cols_);
	~Matrix();
	template<typename C>
	Matrix(const Matrix<C>& m);
	template<typename C>
	void operator=(const Matrix<C>& M2);
	template<typename T,typename C>
	friend bool operator==(const Matrix<T>& M1, const Matrix<C>& M2);
	T* operator[](int num);
	template<typename T, typename C>
	friend Matrix<T> operator+(const Matrix<T>& M1, const Matrix<C>& M2);
	template<typename T, typename C>
	friend Matrix<T> operator-(const Matrix<T>& M1, const Matrix<C>& M2);
	template<typename T, typename C>
	friend Matrix<T> operator*(const Matrix<T>& M1, const Matrix<C>& M2);
	Matrix<T> operator*(int skalar);
	template<typename T>
	friend std::ostream& operator<<(std::ostream& os, Matrix<T>& M);
	template<typename T>
	friend Matrix<T> Transpose(Matrix<T>& M);
	template<typename T>
	friend Matrix<T> Inverse(Matrix<T>& M);
};
#endif // !_Matrix
