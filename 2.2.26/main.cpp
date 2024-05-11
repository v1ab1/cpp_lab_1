#include "ex2.h"
#include <iostream>

int main() {
    int N, M;
    std::cout << "Введите высоту матрицы N (>2): ";
    std::cin >> N;
    if (N <= 2) {
        std::cerr << "N должно быть больше 2." << std::endl;
        return 1;
    }

    std::cout << "Введите ширину матрицы M (<10): ";
    std::cin >> M;
    if (M >= 10) {
        std::cerr << "M должно быть меньше 10." << std::endl;
        return 1;
    }

    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[M];
    }

    std::cout << "Введите элементы матрицы (0 или 1):" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                std::cerr << "Элементы матрицы должны быть 0 или 1." << std::endl;
                for (int k = 0; k <= i; k++) {
                    delete[] matrix[k];
                }
                delete[] matrix;
                return 1;
            }
        }
    }

    std::cout << "Введенная матрица:" << std::endl;
    printMatrix(matrix, N, M);

    transformMatrix(matrix, N, M);

    std::cout << "Преобразованная матрица:" << std::endl;
    printMatrix(matrix, N, M);

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
