#ifndef PAPER_H
#define PAPER_H

#include <string>
#include "Move.h"

class Paper : public Move {
    public:
    std::string getName() const override {
        return "Paper";
    }
    bool beats(const Move* other) const override;
};
    
#endif