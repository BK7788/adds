#include "Zombie.h"
#include <string>

bool Zombie::beats(const Move* other) const {
    std::string otherName = other->getName();
    if (otherName == "Monkey" || otherName == "Pirate") {
        return true;
    }
    return false;
}