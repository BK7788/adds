// EfficientTruckloads.h
#pragma once
#include <unordered_map>

class EfficientTruckloads {
public:
    int numTrucks(int numCrates, int loadSize);
private:
    std::unordered_map<int,int> memo;
    int solve(int numCrates, int loadSize);
};
