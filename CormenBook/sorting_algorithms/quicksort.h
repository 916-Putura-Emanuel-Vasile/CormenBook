//
// Created by Emanuel on 31.07.2021.
//

#ifndef CORMENBOOK_QUICKSORT_H
#define CORMENBOOK_QUICKSORT_H

#include <vector>

template <class T>
int partition(std::vector<T>& data, int begin, int end);

template <class T>
void quicksort(std::vector<T>& data, int begin, int end);

void testQuickSort();

template<class T>
int partition(std::vector<T> &data, int begin, int end) {
    T pivot = data[end];
    int i = begin - 1;
    for (int j = begin; j < end; ++j) {
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[end], data[i + 1]);
    return i + 1;
}

template<class T>
void quicksort(std::vector<T> &data, int begin, int end) {
    if (begin < end) {
        int pivot_index = partition<T>(data, begin, end);
        quicksort(data, begin, pivot_index - 1);
        quicksort(data, pivot_index + 1, end);
    }
}

#endif //CORMENBOOK_QUICKSORT_H
