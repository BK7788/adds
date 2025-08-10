#pragma once
#include "Player.h"
#include <string>

class Computer : public Player {
    std::string name;
public:
    Computer() : name("Computer") {}                 
    explicit Computer(const std::string& n) : name(n) {}

    std::string getName() const override { return name; }  
    Move* makeMove() override;
};
