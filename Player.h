#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Move.h"

class Player {
public:
    virtual ~Player() = default;
    virtual Move* makeMove() = 0; // ownership of returned pointer transfers to caller
    virtual std::string getName() const = 0;
};

#endif // PLAYER_H
