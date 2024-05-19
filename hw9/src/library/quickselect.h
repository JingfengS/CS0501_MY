//
// Created by Jingfeng Sun on 2024/5/19.
//
// 试设计一个函数,在一个规模为N的无序数组中找出第k个大的元素
// (1)要求时间复杂度为 0(N+ klogN)。
// (2)要求时间复杂度为 0(Nlogk)。
// Note that for this problem, since
// QuickSelect algorithm has a time complexity of O(N) on average, therefore
// we can use it to find the kth largest element in an array in O(N) time.
// Which satisfy both requirements.

#ifndef HW9_QUICKSELECT_H
#define HW9_QUICKSELECT_H
#include <quicksort.h>
#include <vector>
template <class T>
T quickSelectHelper(std::vector<T> arr, int k, int left, int right) {
    if (k > 0 && k - 1 <= right) {
        int pivot = partition(arr, left, right);
        if (pivot == k - 1) {
            return arr[pivot];
        }
        if (pivot > k - 1) {
            return quickSelectHelper(arr, k, left, pivot - 1);
        }
        return quickSelectHelper(arr, k, pivot + 1, right);
    }
    return -1;
}

template <class T>
T quickSelect(std::vector<T> arr, int k) {
    if (arr.empty()) {
        throw std::invalid_argument("Empty array");
    }
    if (k <= 0 || k > arr.size()) {
        throw std::invalid_argument("Invalid k");
    }
    return quickSelectHelper(arr, k, 0, arr.size() - 1);
}

#endif //HW9_QUICKSELECT_H
