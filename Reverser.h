#pragma once
#include <string>

class Reverser {
public:
    int reverseDigit(int value);
    std::string reverseString(const std::string& characters);
private:
    int reverseDigitHelper(int value, int acc);
    std::string reverseStringHelper(const std::string& s, size_t i);
};
