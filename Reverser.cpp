#include "Reverser.h"

int Reverser::reverseDigit(int value) {
    if (value < 0) return -1;
    return reverseDigitHelper(value, 0);
}

int Reverser::reverseDigitHelper(int value, int acc) {
    if (value < 10) return acc * 10 + value;
    return reverseDigitHelper(value / 10, acc * 10 + (value % 10));
}

std::string Reverser::reverseString(const std::string& characters) {
    if (characters.empty()) return "ERROR";
    return reverseStringHelper(characters, 0);
}

std::string Reverser::reverseStringHelper(const std::string& s, size_t i) {
    if (i == s.size() - 1) return std::string(1, s[i]);
    return reverseStringHelper(s, i + 1) + s[i];
}
