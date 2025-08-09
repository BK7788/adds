#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <string>
#include <vector>

class Computer : public Player {
    std::string name;
public:
    explicit Computer(std::string name = "Computer");
    Move* makeMove() override;
    std::string getName() const override { return name; }
};
#endif
