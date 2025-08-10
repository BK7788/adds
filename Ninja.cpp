#include "Ninja.h"
#include <string>

bool Ninja::beats(const Move* other) const {
    std::string otherName = other->getName();
    if (otherName == "Zombie" || otherName == "Pirate") {
        return true;
    }
    return false;
}