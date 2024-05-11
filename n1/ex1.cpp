#include "ex1.h"
#include <bitset>

void addBinaryToEachElement(std::vector<std::string>& binaries, const std::string& toAdd) {
    int toAddDecimal = std::bitset<32>(toAdd).to_ulong(); // Преобразуем двоичное число в десятичное

    for (std::string& binary : binaries) {
        int binaryDecimal = std::bitset<32>(binary).to_ulong(); 
        int newDecimal = binaryDecimal + toAddDecimal;
        binary = std::bitset<32>(newDecimal).to_string(); // Обрезаем начальные нули
        binary.erase(0, binary.find_first_not_of('0'));
    }
}
