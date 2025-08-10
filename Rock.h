#ifndef ROCK_H
#define ROCK_H

#include <string>
#include "Move.h"

class Rock : public Move {
    public:
    std::string getName() const override {
        return "Rock";
    }
    bool beats(const Move* other) const override;
};
    
#endif