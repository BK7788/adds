#ifndef MOVE_H
#define MOVE_H
#include <string>

class Move {
    public:
    virtual std::string getName() const = 0;
    virtual bool beats(const Move* other) const = 0;
    virtual ~Move() {};
};

#endif