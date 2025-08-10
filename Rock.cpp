#include "Rock.h"
#include <string>

bool Rock::beats(const Move* other) const {
    std::string otherName = other->getName();
    if (otherName == "Scissors") {
        return true;
    }
    return false;
}