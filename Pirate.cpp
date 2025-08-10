#include "Pirate.h"
#include <string>

bool Pirate::beats(const Move* other) const {
    std::string otherName = other->getName();
    if (otherName == "Robot" || otherName == "Monkey") {
        return true;
    }
    return false;
}