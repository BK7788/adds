#pragma once
#include <string>

class Move {
public:
    virtual ~Move() = default;
    virtual std::string getName() const = 0;
    virtual bool defeats(const Move& other) const = 0;

    static Move* fromName(const std::string& name);
};
