#include <bits/stdc++.h>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    if (!getline(cin, line)) return 0;
    stringstream ss(line);
    vector<int> v;
    int x;
    while (ss >> x) v.push_back(x);
    QuickSort qs;
    vector<int> sorted = qs.sort(v);
    RecursiveBinarySearch rbs;
    bool hasOne = rbs.search(sorted, 1);
    cout << (hasOne ? "true" : "false");
    for (size_t i = 0; i < sorted.size(); ++i) {
        cout << (i == 0 ? " " : " ") << sorted[i];
    }
    cout << "\n";
    return 0;
}
