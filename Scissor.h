#ifndef SCISSORS_H
#define SCISSORS_H

#include <string>
#include "Move.h"

class Scissors : public Move {
    public:
    std::string getName() const override {
        return "Scissors";
    }
    bool beats(const Move* other) const override;
};
    
#endif