#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Sort.h"
class QuickSort : public Sort {
public:
    std::vector<int> sort(const std::vector<int>& list) override;
};
#endif
