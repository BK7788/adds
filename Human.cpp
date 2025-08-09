#include "Human.h"
#include "Move.h"
#include <iostream>
#include <limits>

Human::Human(std::string name) : name(std::move(name)) {}

Move* Human::makeMove() {
    std::cout << "Enter Move: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        // If previous extraction left newline, try again once
        std::getline(std::cin, input);
    }
    Move* m = createMoveByName(input);
    if (! m) {
        std::cout << "Invalid move typed: \"" << input << "\". Valid options are:\n"
                  << "Rock, Paper, Scissors, Robot, Monkey, Pirate, Ninja, Zombie\n";
        return nullptr; // behaviour is undefined per spec; the testing main won't rely on this path
    }
    return m;
}
