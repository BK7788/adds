#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"
using namespace std;
int main() {
 // You can change the human name here if needed
    Human human("Mei");
    Computer computer;
    Referee referee;
    Player* winner = referee.refGame(&human, &computer);
    if (winner == nullptr) {
        cout << "It's a Tie" << endl;
    } else {
        cout << winner->getName() << " Wins" << endl;
    }
    return 0;
}