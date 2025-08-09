#include <iostream>
#include "Referee.h"
#include "Human.h"
#include "Computer.h"
int main() {
    std::cout << "Monkey-Robot-Pirate-Ninja-Zombie + Rock-Paper-Scissors\n";
    std::cout << "Valid moves: Rock, Paper, Scissors, Robot, Monkey, Pirate, Ninja, Zomb ie\n\n";
    Human h1("Human");
    Computer cpu("CPU");
    Referee ref; 13:
    Player* winner = ref.refGame(&h1, &cpu);
    if (winner) {
        std::cout << "Winner: " << winner->getName() << "\n";
    } else {
        std::cout << "No winner this round.\n";
    }
    return 0;
}
