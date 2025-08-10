#include "Referee.h"
#include "Player.h"
#include "Move.h"

Player* Referee::refGame(Player* p1, Player* p2) {
    Move* m1 = p1->makeMove();
    Move* m2 = p2->makeMove();

    Player* winner = nullptr;
    const bool p1wins = m1->defeats(*m2) && !m2->defeats(*m1);
    const bool p2wins = m2->defeats(*m1) && !m1->defeats(*m2);

    if (p1wins)      winner = p1;
    else if (p2wins) winner = p2;


    delete m1;
    delete m2;
    return winner;
}
