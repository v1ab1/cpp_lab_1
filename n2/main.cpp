#include "ex2.h"
#include <iostream>
#include <vector>

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

    std::vector<std::vector<int>> matrix(N, std::vector<int>(M));
    std::cout << "Введите элементы матрицы (0 или 1):" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                std::cerr << "Элементы матрицы должны быть 0 или 1." << std::endl;
                return 1;
            }
        }
    }

    std::cout << "Введенная матрица:" << std::endl;
    printMatrix(matrix, N, M);

    transformMatrix(matrix, N, M);

    std::cout << "Преобразованная матрица:" << std::endl;
    printMatrix(matrix, N, M);

    return 0;
}
