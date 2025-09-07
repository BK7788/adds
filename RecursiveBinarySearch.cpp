#include "RecursiveBinarySearch.h"
using namespace std;

static bool rbs(const vector<int>& a, int l, int r, int x) {
    if (l > r) return false;
    int m = l + (r - l) / 2;
    if (a[m] == x) return true;
    if (x < a[m]) return rbs(a, l, m - 1, x);
    return rbs(a, m + 1, r, x);
}

bool RecursiveBinarySearch::search(const vector<int>& sorted, int target) {
    if (sorted.empty()) return false;
    return rbs(sorted, 0, (int)sorted.size() - 1, target);
}
