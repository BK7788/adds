#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <iostream>
#include <string>

class Human : public Player {
    private:
        std::string name;
    public:
        Human( std::string name = "Human");
        Move* makeMove() override;
        std::string getName() override;
};

#endif