#include <iostream>
#include "ex1.h"
#include <vector>
#include <string>

int main() {
    std::vector<std::string> binaries;
    std::string input;
    int numberOfBinaries;

    std::cout << "Введите количество чисел: ";
    std::cin >> numberOfBinaries;

    std::cout << "Введите бинарные числа:\n";
    for (int i = 0; i < numberOfBinaries; ++i) {
        std::cin >> input;

        for (char c : input) {
            if (c != '0' && c != '1') {
                std::cerr << "Необходимо вводить только числа в двоичной системе" << std::endl;
                return 1;
            }
        }

        binaries.push_back(input);
    }

    const std::string addValue = "1010";

    std::cout << "\nВведенные двоичные числа:\n";
    for (const auto& bin : binaries) {
        std::cout << bin << "\n";
    }

    addBinaryToEachElement(binaries, addValue);

    std::cout << "\nЧисла после увелечения:\n";
    for (const auto& bin : binaries) {
        std::cout << bin << "\n";
    }

    return 0;
}
