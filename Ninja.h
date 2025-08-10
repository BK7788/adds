#include "Paper.h"
#include <string>

bool Paper::beats(const Move* other) const {
    std::string otherName = other->getName();
    if (otherName == "Rock") {
        return true;
    }
    return false;
}