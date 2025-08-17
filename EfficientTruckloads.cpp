// EfficientTruckloads.cpp
#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    memo.clear();
    return solve(numCrates, loadSize);
}

int EfficientTruckloads::solve(int numCrates, int loadSize) {
    if (numCrates <= loadSize) return 1;
    if (auto it = memo.find(numCrates); it != memo.end()) return it->second;
    int left = numCrates / 2, right = numCrates - left;
    int ans = solve(left, loadSize) + solve(right, loadSize);
    memo[numCrates] = ans;
    return ans;
}
