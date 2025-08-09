#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <string>

class Human : public Player {
    std::string name;
public:
    explicit Human(std::string name);
    Move* makeMove() override; // may return nullptr if invalid input (undefined behavio ur per spec)
    std::string getName() const override { return name; }
};
#endif
