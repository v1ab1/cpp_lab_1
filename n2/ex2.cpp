#include "ex2.h"
#include <iostream>
#include <algorithm>
#include <vector>

void swapColumns(std::vector<std::vector<int>>& matrix, int col1, int col2, int N) {
    for (int i = 0; i < N; i++) {
        std::swap(matrix[i][col1], matrix[i][col2]);
    }
}

void transformMatrix(std::vector<std::vector<int>>& matrix, int N, int M) {
    std::vector<int> priority(M, 0);

    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            if (matrix[i][j] == 1) {
                priority[j] = N - i;
                break;
            }
        }
    }

    for (int i = 0; i < M - 1; ++i) {
        for (int j = i + 1; j < M; ++j) {
            if (priority[i] < priority[j]) {
                swapColumns(matrix, i, j, N);
                std::swap(priority[i], priority[j]);
            }
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix, int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
