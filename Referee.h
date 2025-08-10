#pragma once
class Player;

class Referee {
public:
    Referee() = default;
    
    Player* refGame(Player* player1, Player* player2);
};
