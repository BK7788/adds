#include "Move.h"
#include <unordered_set>
#include <algorithm>

using std::string;
using std::unordered_set;

namespace {
   
    struct SimpleMove : Move {
        string name;
        unordered_set<string> wins;
        SimpleMove(string n, unordered_set<string> w) : name(std::move(n)), wins(std::move(w)) {}
        std::string getName() const override { return name; }
        bool defeats(const Move& other) const override { return wins.count(other.getName()) > 0; }
    };

  
    string normalize(const string& s) {
        string t = s;
        std::transform(t.begin(), t.end(), t.begin(), [](unsigned char c){ return std::tolower(c); });
        return t;
    }
}


Move* Move::fromName(const std::string& inputName) {
    const string key = normalize(inputName);

    if (key == "rock")     return new SimpleMove("Rock",     {"Scissors", "Monkey"});
    if (key == "paper")    return new SimpleMove("Paper",    {"Rock", "Robot"});
    if (key == "scissors") return new SimpleMove("Scissors", {"Paper", "Zombie"});

    if (key == "monkey")   return new SimpleMove("Monkey",   {"Ninja", "Robot"});
    if (key == "robot")    return new SimpleMove("Robot",    {"Ninja", "Zombie"});
    if (key == "pirate")   return new SimpleMove("Pirate",   {"Robot", "Monkey"});
    if (key == "ninja")    return new SimpleMove("Ninja",    {"Pirate", "Zombie"});
    if (key == "zombie")   return new SimpleMove("Zombie",   {"Pirate", "Monkey"});

    
    return new SimpleMove("Rock", {"Scissors", "Monkey"});
}
