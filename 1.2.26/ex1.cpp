#include "ex1.h"
#include <string>
#include <algorithm>
#include <cmath>

int binaryStringToDecimal(const std::string& binary) {
    int decimal = 0;
    int length = binary.length();
    for (int i = 0; i < length; ++i) {
        if (binary[length - 1 - i] == '1') {
            decimal += (1 << i);
        }
    }
    return decimal;
}

std::string decimalToBinaryString(int decimal) {
    if (decimal == 0) return "0";
    std::string binary;
    while (decimal > 0) {
        binary.push_back('0' + (decimal % 2));
        decimal /= 2;
    }
    std::reverse(binary.begin(), binary.end());
    return binary;
}

void addBinaryToEachElement(std::string* binaries, int size, const std::string& toAdd) {
    int toAddDecimal = binaryStringToDecimal(toAdd);

    for (int i = 0; i < size; ++i) {
        int binaryDecimal = binaryStringToDecimal(binaries[i]);
        int newDecimal = binaryDecimal + toAddDecimal;
        binaries[i] = decimalToBinaryString(newDecimal);
    }
}
