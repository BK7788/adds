#include "Scissors.h"
#include <string>

bool Scissors::beats(const Move* other) const {
    std::string otherName = other->getName();
    if (otherName == "Paper") {
        return true;
    }
    return false;
}