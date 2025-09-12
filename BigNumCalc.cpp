#include "BigNumCalc.h"
#include <algorithm>
#include <cctype>
#include <vector>

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
    while (ia != a.end() || ib != b.end()) {
        int da = ia != a.end() ? *ia++ : 0;
        int db = ib != b.end() ? *ib++ : 0;
        int d = da - borrow - db;
        if (d < 0) { d += 10; borrow = 1; } else borrow = 0;
        r.push_back(d);
    }
    trim(r);
    return r;
}

list<int> BigNumCalc::mul(const list<int>& a, const list<int>& b) {
    if ((a.size() == 1 && *a.begin() == 0) || (b.size() == 1 && *b.begin() == 0)) return list<int>{0};
    size_t na = a.size(), nb = b.size();
    std::vector<int> v(na + nb, 0);
    size_t i = 0;
    for (int da : a) {
        size_t j = 0;
        int carry = 0;
        for (int db : b) {
            size_t idx = i + j;
            long long cur = v[idx] + da * db + carry;
            v[idx] = static_cast<int>(cur % 10);
            carry = static_cast<int>(cur / 10);
            ++j;
        }
        size_t idx = i + j;
        while (carry) {
            long long cur = v[idx] + carry;
            v[idx] = static_cast<int>(cur % 10);
            carry = static_cast<int>(cur / 10);
            ++idx;
        }
        ++i;
    }
    while (v.size() > 1 && v.back() == 0) v.pop_back();
    list<int> r;
    for (int d : v) r.push_back(d);
    trim(r);
    return r;
}
