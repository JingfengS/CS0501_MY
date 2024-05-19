//
// Created by Jingfeng Sun on 2024/5/19.
//

#ifndef HW9_QUICKSORT_H
#define HW9_QUICKSORT_H
#include <vector>

template<class T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low;
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

template <class T>
void quicksort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

template <class T>
void quicksort(std::vector<T>& arr) {
    quicksort(arr, 0, arr.size() - 1);
}
#endif //HW9_QUICKSORT_H
