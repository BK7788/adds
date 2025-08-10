#include "Computer.h"
#include "Move.h"

Move* Computer::makeMove() {
    return Move::fromName("Rock");
}
