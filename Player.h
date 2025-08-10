#pragma once
#include <string>

class Move;

class Player {
public:
    virtual ~Player() = default;
    virtual Move* makeMove() = 0;       
    virtual std::string getName() = 0;
};
