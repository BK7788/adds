#include <iostream>
#include "Referee.h"
#include "Human.h"
#include "Computer.h"

int main() {
    Referee ref;
    Human    h("Human");
    Computer c("Computer");

    auto* winner = ref.refGame(&h, &c);
    if (winner) std::cout << winner->getName() << "\n";
    else        std::cout << "Tie\n";
    return 0;
}
