#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    memo.clear();
    return solve(numCrates, loadSize);
}

int EfficientTruckloads::solve(int numCrates, int loadSize) {
    if (numCrates <= loadSize) return 1;
    auto key = std::make_pair(numCrates, loadSize);
    auto it = memo.find(key);
    if (it != memo.end()) return it->second;
    int left = numCrates / 2;
    int right = numCrates - left;
    int ans = solve(left, loadSize) + solve(right, loadSize);
    memo[key] = ans;
    return ans;
}
