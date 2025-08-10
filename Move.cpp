#include "Move.h"
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cctype>

// ------------------------
// Utilities
// ------------------------
std::string toLowerCopy(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
                    [](unsigned char c){ return std::tolower(c); });
    return out;
}
class SimpleMove : public Move {
protected:
    std::string name;
    // canonical, lowercase names this move defeats
    std::unordered_set<std::string> winsOver;
public:
    explicit SimpleMove(const std::string& n, std::unordered_set<std::string> beats)
    : name(n), winsOver(std::move(beats)) {}
    std::string getName() const override { return name; }
    bool defeats(const Move& other) const override {
        return winsOver.find(toLowerCopy(other.getName())) != winsOver.end();
    }
};

static std::unordered_map<std::string, std::unordered_set<std::string>> RULES = {
    // Rock Paper Scissors
    {"rock",     {"scissors"}},
    {"paper",    {"rock"}},
    {"scissors", {"paper"}},

    {"monkey",   {"pirate", "robot"}},
    {"robot",    {"pirate", "zombie"}},
    {"pirate",   {"ninja", "monkey"}},
    {"ninja",    {"robot", "zombie"}},
    {"zombie",   {"monkey", "pirate"}}
};

static std::unordered_map<std::string, std::string> CANON_NAMES = {
    {"rock","Rock"}, {"paper","Paper"}, {"scissors","Scissors"},
    {"monkey","Monkey"}, {"robot","Robot"}, {"pirate","Pirate"},
    {"ninja","Ninja"}, {"zombie","Zombie"}
};
Move* createMoveByName(const std::string& fullName) {
    std::string key = toLowerCopy(fullName);
    auto it = RULES.find(key);
    if (it == RULES.end()) return nullptr;
    return new SimpleMove(CANON_NAMES[key], it->second);
}

