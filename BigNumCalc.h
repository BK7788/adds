#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include <list>
#include <string>

class BigNumCalc {
public:
    std::list<int> buildBigNum(const std::string& s);
    std::list<int> add(const std::list<int>& a, const std::list<int>& b);
    std::list<int> sub(const std::list<int>& a, const std::list<int>& b);
    std::list<int> mul(const std::list<int>& a, const std::list<int>& b);
private:
    static void trim(std::list<int>& x);
    static int cmpAbs(const std::list<int>& a, const std::list<int>& b);
};

#endif
