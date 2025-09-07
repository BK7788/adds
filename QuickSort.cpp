#include "QuickSort.h"
#include <vector>
using namespace std;

static int partition_third_pivot(vector<int>& a, int l, int r) {
    int len = r - l + 1;
    int pidx = len >= 3 ? l + 2 : r;
    int pivot = a[pidx];
    int t = a[pidx]; a[pidx] = a[r]; a[r] = t;
    int i = l;
    for (int j = l; j < r; ++j) {
        if (a[j] < pivot) {
            int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            ++i;
        }
    }
    int tmp = a[i]; a[i] = a[r]; a[r] = tmp;
    return i;
}

static void qsort_third(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = partition_third_pivot(a, l, r);
    qsort_third(a, l, p - 1);
    qsort_third(a, p + 1, r);
}

vector<int> QuickSort::sort(const vector<int>& list) {
    vector<int> a = list;
    if (!a.empty()) qsort_third(a, 0, (int)a.size() - 1);
    return a;
}
