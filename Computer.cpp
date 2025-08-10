#include "Computer.h"
#include "Move.h"
#include <random>
#include <chrono>
#include <vector>

Computer::Computer(std::string n) : name(std::move(n)) {}

Move* Computer::makeMove() {
    static std::vector<std::string> options = {
        "Rock","Paper","Scissors","Monkey","Robot","Pirate","Ninja","Zombie"
    };
    static std::mt19937 rng(
        static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_e poch().count())
    );
    std::uniform_int_distribution<int> dist(0, static_cast<int>(options.size()) - 1);
    return createMoveByName(options[dist(rng)]);
}
