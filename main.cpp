#include "matrix.h"
int main() {
    Matrix<int> m1(2, 2); // tworzenie macierzy 3x3
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 4;
    m1[1][1] = 5;

    Matrix<double> m2(2, 2); // tworzenie macierzy 3x3
    m2[0][0] = 7.6;
    m2[0][1] = 8.7;
    m2[1][0] = 10.8;
    m2[1][1] = 11.9;
    Matrix<double> m3 = m1 * m2; // mno¿enie macierzy
    std::cout << "Wynik mno¿enia m1 i m2:" << std::endl;
    std::cout << m3 << std::endl;

    Matrix<double> m4 = Transpose(m1); // transpozycja macierzy
    std::cout << "Transpozycja m1:" << std::endl;
    std::cout << m4 << std::endl;

    Matrix<double> m5 = Inverse(m1); // macierz odwrotna
    std::cout << "Macierz odwrotna do m1:" << std::endl;
    std::cout << m5 << std::endl;

    Matrix<double> m6 = m1 + m2; // dodawanie macierzy
    std::cout << "Wynik dodawania m1 i m2:" << std::endl;
    std::cout << m6 << std::endl;

    Matrix<double> m7 = m1 - m2; // odejmowanie macierzy
    std::cout << "Wynik odejmowania m1 i m2:" << std::endl;
    std::cout << m7 << std::endl;

    Matrix<double> m8 = m1 * 2; // mno¿enie macierzy przez skalar
    std::cout << "Mno¿enie m1 przez 2:" << std::endl;
    std::cout << m8 << std::endl;

    return 0;
}