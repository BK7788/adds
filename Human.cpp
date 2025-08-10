#include "Human.h"
#include "Move.h"
#include <string>
#include <iostream>

Move* Human::makeMove() {
    std::string in;
    if (!(std::cin >> in)) in = "Rock";
    return Move::fromName(in);
}
