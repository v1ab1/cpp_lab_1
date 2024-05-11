#include <iostream>
#include <string>
#include "ex1.h"

int main() {
    std::string* binaries;
    std::string input;
    int numberOfBinaries;

    std::cout << "Введите количество чисел: ";
    std::cin >> numberOfBinaries;
    binaries = new std::string[numberOfBinaries];

    std::cout << "Введите бинарные числа:\n";
    for (int i = 0; i < numberOfBinaries; ++i) {
        std::cin >> input;

        for (char c : input) {
            if (c != '0' && c != '1') {
                std::cerr << "Необходимо вводить только числа в двоичной системе" << std::endl;
                delete[] binaries;
                return 1;
            }
        }

        binaries[i] = input;
    }

    const std::string addValue = "1010";

    std::cout << "\nВведенные двоичные числа:\n";
    for (int i = 0; i < numberOfBinaries; ++i) {
        std::cout << binaries[i] << "\n";
    }

    addBinaryToEachElement(binaries, numberOfBinaries, addValue);

    std::cout << "\nЧисла после увелечения:\n";
    for (int i = 0; i < numberOfBinaries; ++i) {
        std::cout << binaries[i] << "\n";
    }

    delete[] binaries;
    return 0;
}
