#ifndef SORT_H
#define SORT_H
#include <vector>

class Sort {
public:
    virtual ~Sort() {}
    virtual std::vector<int> sort(const std::vector<int>& list) = 0;
};

#endif
