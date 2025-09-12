#include "BigNumCalc.h"
#include <vector>
#include <cctype>

using std::list;
using std::string;

static inline bool is_digit(char c){
    return std::isdigit(static_cast<unsigned char>(c));
}

list<int> BigNumCalc::buildBigNum(const string& s) {
    list<int> x;
    for(char c: s) if(is_digit(c)) x.push_back(c - '0');
    if(x.empty()) x.push_back(0);
    trim(x);
    return x;
}

void BigNumCalc::trim(list<int>& x) {
    while (x.size() > 1 && x.front() == 0) x.pop_front();
}

int BigNumCalc::cmpAbs(const list<int>& a, const list<int>& b) {
    if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    auto ia = a.begin(), ib = b.begin();
    for (; ia != a.end(); ++ia, ++ib) {
        if (*ia != *ib) return *ia < *ib ? -1 : 1;
    }
    return 0;
}

list<int> BigNumCalc::add(const list<int>& a, const list<int>& b) {
    list<int> r;
    auto ia = a.rbegin(), ib = b.rbegin();
    int carry = 0;
    while (ia != a.rend() || ib != b.rend() || carry) {
        int da = ia != a.rend() ? *ia++ : 0;
        int db = ib != b.rend() ? *ib++ : 0;
        int s = da + db + carry;
        r.push_front(s % 10);
        carry = s / 10;
    }
    trim(r);
    return r;
}

list<int> BigNumCalc::sub(const list<int>& a, const list<int>& b) {
    int c = cmpAbs(a, b);
    if (c == 0) return list<int>{0};
    const list<int>* big = &a;
    const list<int>* small = &b;
    if (c < 0) { big = &b; small = &a; }
    list<int> r;
    auto ia = big->rbegin();
    auto ib = small->rbegin();
    int borrow = 0;
    while (ia != big->rend() || ib != small->rend()) {
        int da = ia != big->rend() ? *ia++ : 0;
        int db = ib != small->rend() ? *ib++ : 0;
        int d = da - borrow - db;
        if (d < 0) { d += 10; borrow = 1; } else borrow = 0;
        r.push_front(d);
    }
    trim(r);
    return r;
}

list<int> BigNumCalc::mul(const list<int>& a, const list<int>& b) {
    if ((a.size() == 1 && a.front() == 0) || (b.size() == 1 && b.front() == 0))
        return list<int>{0};

    std::vector<int> va; va.reserve(a.size());
    std::vector<int> vb; vb.reserve(b.size());
    for (auto it = a.rbegin(); it != a.rend(); ++it) va.push_back(*it);
    for (auto it = b.rbegin(); it != b.rend(); ++it) vb.push_back(*it);

    std::vector<int> v(va.size() + vb.size(), 0);
    for (size_t i = 0; i < va.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < vb.size(); ++j) {
            long long cur = v[i + j] + va[i] * vb[j] + carry;
            v[i + j] = static_cast<int>(cur % 10);
            carry = static_cast<int>(cur / 10);
        }
        size_t k = i + vb.size();
        while (carry) {
            long long cur = v[k] + carry;
            v[k] = static_cast<int>(cur % 10);
            carry = static_cast<int>(cur / 10);
            ++k;
        }
    }
    while (v.size() > 1 && v.back() == 0) v.pop_back();

    list<int> r;
    for (size_t i = v.size(); i-- > 0; ) r.push_back(v[i]);
    trim(r);
    return r;
}
