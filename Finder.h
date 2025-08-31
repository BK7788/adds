#ifndef FINDER_H
#define FINDER_H

#include <iostream>
#include <chrono>
#include <string>
#include <vector>

namespace finder_internal {
struct FastIO { FastIO(){ std::ios::sync_with_stdio(false); std::cin.tie(nullptr); } };
inline FastIO fastio_guard{};
}

class Finder {
public:
    std::vector<int> findSubstrings(const std::string& s1, const std::string& s2);
};

#endif
