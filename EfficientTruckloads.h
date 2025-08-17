#pragma once
#include <unordered_map>
#include <utility>
#include <functional>

struct PairHash {
    size_t operator()(const std::pair<int,int>& p) const {
        return std::hash<long long>()((static_cast<long long>(p.first) << 32) ^ p.second);
    }
};

class EfficientTruckloads {
public:
    int numTrucks(int numCrates, int loadSize);
private:
    std::unordered_map<std::pair<int,int>, int, PairHash> memo;
    int solve(int numCrates, int loadSize);
};
