#include "Computer.h"

#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Monkey.h"
#include "Robot.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

Move* Computer::makeMove() {
    return new Rock();
}

std::string Computer::getName() {
    return "Computer";
}