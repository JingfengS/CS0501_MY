//
// Created by Jingfeng Sun on 2024/5/19.
//

#ifndef HW9_REMOVEDUPLICATES_H
#define HW9_REMOVEDUPLICATES_H
#include <quicksort.h>
#include <vector>
#include <queue>
template <class T>
void removeDuplicatesHelper(std::vector<T>&sorted) {
    if (sorted.empty()) {
        return;
    }
    T lastElement = sorted.back();
    sorted.pop_back();
    removeDuplicatesHelper(sorted);
    if (sorted.back() == lastElement) {
        return;
    } else {
        sorted.push_back(lastElement);
    }
}

template <class T>
void removeDuplicates(std::vector<T>& arr) {
    quicksort(arr);
    removeDuplicatesHelper(arr);
}

#endif //HW9_REMOVEDUPLICATES_H
