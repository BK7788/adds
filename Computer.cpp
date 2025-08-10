#include "Computer.h"
#include "Move.h"
#include <vector>
#include <random>
#include <chrono>

Move* Computer::makeMove() {
    static const std::vector<std::string> names = {
        "Rock","Paper","Scissors","Robot","Monkey","Pirate","Ninja","Zombie"
    };
    static thread_local std::mt19937 rng(
        static_cast<unsigned int>(
            std::chrono::steady_clock::now().time_since_epoch().count()
        )
    );
    std::uniform_int_distribution<int> dist(0, static_cast<int>(names.size()) - 1);
    return Move::fromName(names[dist(rng)]);
}
