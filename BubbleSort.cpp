#include "BubbleSort.h"
#include <vector>
using namespace std;

vector<int> BubbleSort::sort(const vector<int>& list) {
    vector<int> a = list;
    int n = (int)a.size();
    bool swapped = true;
    for (int i = 0; i < n - 1 && swapped; ++i) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swapped = true;
            }
        }
    }
    return a;
}
