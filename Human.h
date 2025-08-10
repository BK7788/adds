#pragma once
#include "Player.h"
#include <string>

class Human : public Player {
    std::string name;
public:
    Human() : name("Human") {}                        
    explicit Human(const std::string& n) : name(n) {}

    std::string getName() const override { return name; }  
    Move* makeMove() override;
};
