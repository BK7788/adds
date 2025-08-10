#include "Human.h"
#include <iostream>

#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Monkey.h"
#include "Robot.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

Human::Human(std::string name) : name(name) {}

Move* Human::makeMove() {
    std::cout << "Enter move : ";
    std::string input;
    std::cin >> input;

    if (input == "Rock")      return new Rock();
    if (input == "Paper")     return new Paper();
    if (input == "Scissors")  return new Scissors();
    if (input == "Monkey")    return new Monkey();
    if (input == "Robot")     return new Robot();
    if (input == "Pirate")    return new Pirate();
    if (input == "Ninja")     return new Ninja();
    if (input == "Zombie")    return new Zombie();

    std::cout << "Invalid move. Defaulting to Rock." << std::endl;
    return new Rock();
}

std::string Human::getName() {
    return name;
}