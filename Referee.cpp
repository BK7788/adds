#include "Referee.h"
#include "Move.h"
#include <iostream>
Player* Referee::refGame(Player* player1, Player* player2) {
    if (! player1 ||  ! player2) return nullptr;

    Move* m1 = player1->makeMove();
    Move* m2 = player2->makeMove(); 10:
    if (! m1 || ! m2) {
        // undefined behaviour in spec; keep safe and report
        std::cout << "One or both moves invalid. No result.\n";
        delete m1; delete m2;
        return nullptr;
    } 17:
    if (m1->defeats(*m2) && ! m2->defeats(*m1)) {
        delete m1; delete m2;
        return player1;
    } else if (m2->defeats(*m1) && ! m1->defeats(*m2)) {
        delete m1; delete m2;
        return player2;
    } else {
        std::cout << "It's a draw between " << m1->getName() << " and " << m2->getName() << ".\n";
        delete m1; delete m2;
        return nullptr;
    }
}
