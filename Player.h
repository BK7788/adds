#pragma once
#include <string>

class Move;  // 前向声明，避免循环包含

class Player {
public:
    virtual ~Player() = default;
    virtual Move* makeMove() = 0;             
    virtual std::string getName() const = 0;   
};
