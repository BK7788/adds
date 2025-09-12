#include "BigNumCalc.h"
#include <algorithm>
#include <cctype>

using std::list;
using std::string;

list<int> BigNumCalc::buildBigNum(const string& s) {
    list<int> x;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (std::isdigit(static_cast<unsigned char>(*it))) x.push_back(*it - '0');
    }
    if (x.empty()) x.push_back(0);
    trim(x);
    return x;
}

void BigNumCalc::trim(list<int>& x) {
    while (x.size() > 1 && x.back() == 0) x.pop_back();
}

int BigNumCalc::cmpAbs(const list<int>& a, const list<int>& b) {
    if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    auto ia = a.rbegin(), ib = b.rbegin();
    for (; ia != a.rend(); ++ia, ++ib) {
        if (*ia != *ib) return *ia < *ib ? -1 : 1;
    }
    return 0;
}

list<int> BigNumCalc::add(const list<int>& a, const list<int>& b) {
    list<int> r;
    auto ia = a.begin(), ib = b.begin();
    int carry = 0;
    while (ia != a.end() || ib != b.end() || carry) {
        int da = ia != a.end() ? *ia++ : 0;
        int db = ib != b.end() ? *ib++ : 0;
        int s = da + db + carry;
        r.push_back(s % 10);
        carry = s / 10;
    }
    trim(r);
    return r;
}

list<int> BigNumCalc::sub(const list<int>& a, const list<int>& b) {
    if (cmpAbs(a, b) < 0) return list<int>{0};
    list<int> r;
    auto ia = a.begin(), ib = b.begin();
    int borrow = 0;
    whi
