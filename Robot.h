#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include "Move.h"

class Robot : public Move {
    public:
    std::string getName() const override {
        return "Robot";
    }
    bool beats(const Move* other) const override;
};
    
#endif