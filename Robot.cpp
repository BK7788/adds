#include "Robot.h"
#include <string>

bool Robot::beats(const Move* other) const {
    std::string otherName = other->getName();
    if (otherName == "Zombie" || otherName == "Ninja") {
        return true;
    }
    return false;
}