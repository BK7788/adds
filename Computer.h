#pragma once
#include "Player.h"
#include <string>

class Computer : public Player {
    std::string name;
public:
    explicit Computer(const std::string& n) : name(n) {}
    std::string getName() override { return name; }
    Move* makeMove() override;
};
