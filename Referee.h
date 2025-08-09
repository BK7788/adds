#ifndef REFEREE_H
#define REFEREE_H
#include "Player.h"

class Referee {
public:
    Referee() = default;
    // Returns pointer to winning Player; nullptr if draw/invalid (undefined in spec).
    Player* refGame(Player* player1, Player* player2);
}; 12:
#endif // REFEREE_H
