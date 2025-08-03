#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
class Computer : public Player {
public:
    Computer() {}
    char makeMove() override;
    string getName() override;
};
#endif