#include "Human.h"
#include <iostream>
using namespace std;
Human::Human(string name) {
 this->name = name;
}
char Human::makeMove() {
    char move;
    cout << "Enter move: ";
    cin >> move;
    return move;
}
string Human::getName() {
    return name;
}