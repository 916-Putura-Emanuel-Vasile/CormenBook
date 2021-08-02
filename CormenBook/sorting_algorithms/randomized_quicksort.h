//
// Created by Emanuel on 02.08.2021.
//

#ifndef CORMENBOOK_RANDOMIZED_QUICKSORT_H
#define CORMENBOOK_RANDOMIZED_QUICKSORT_H

#include <vector>
#include <cstdlib>

template <class T>
int basicPartition(std::vector<T>& data, int begin, int end);

template <class T>
int randomizedPartition(std::vector<T>& data, int begin, int end);

template <class T>
void randomizedQuickSort(std::vector<T>& data, int begin, int end);

void testRandomizedQuickSort();

// ================================================================================

template<class T>
int basicPartition(std::vector<T> &data, int begin, int end) {
    auto pivot = data[end];
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
int randomizedPartition(std::vector<T> &data, int begin, int end) {
    int pivot_index = rand() % (end - begin + 1) + begin;
    std::swap(data[pivot_index], data[end]);
    return basicPartition<T>(data, begin, end);
}

template<class T>
void randomizedQuickSort(std::vector<T> &data, int begin, int end) {
    if (begin < end) {
        int pivot_index = randomizedPartition<T>(data, begin, end);
        randomizedQuickSort<T>(data, begin, pivot_index - 1);
        randomizedQuickSort<T>(data, pivot_index + 1, end);
    }
}

#endif //CORMENBOOK_RANDOMIZED_QUICKSORT_H
