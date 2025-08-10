#include "Human.h"
#include "Move.h"
#include <iostream>
#include <string>

Move* Human::makeMove() {
    std::cout << "Enter Move: ";
    std::string in;
    if (!(std::cin >> in)) in = "Rock";   // 输入失败兜底
    return Move::fromName(in);
}

