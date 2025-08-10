#pragma once
#include "Player.h"
#include <string>

class Human : public Player {
    std::string name;
public:
    explicit Human(const std::string& n) : name(n) {}
    std::string getName() override { return name; }
    Move* makeMove() override;
};
