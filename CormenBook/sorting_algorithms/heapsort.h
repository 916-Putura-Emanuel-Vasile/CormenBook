//
// Created by Emanuel on 28.07.2021.
//

#ifndef CORMENBOOK_HEAPSORT_H
#define CORMENBOOK_HEAPSORT_H

/*
 * HeapSort Algorithm
 * -> Time Complexity: O(n*lg(n))
 * -> Extra Space Complexity: in-place sorting algorithm
 */

#include <vector>

template <class T>
void buildMaxHeap(std::vector<T>& data);

template <class T>
void maxHeapify(std::vector<T>& data, int size, int index);

template <class T>
void heapsort(std::vector<T>& data);

void testHeapSort();

template<class T>
void buildMaxHeap(std::vector<T> &data) {
    for (int i = (data.size() - 1) / 2; i >= 0; --i)
        maxHeapify(data, data.size(), i);
}

template<class T>
void maxHeapify(std::vector<T> &data, int size, int index) {
    while (index < size) {
        int right = index * 2 + 1, left = index * 2 + 2, maximum = index;

        if (left < size && data[maximum] < data[left])
            maximum = left;
        if (right < size && data[maximum] < data[right])
            maximum = right;

        std::swap(data[index], data[maximum]);
        if (index == maximum) break;
        index = maximum;
    }
}

template<class T>
void heapsort(std::vector<T> &data) {
    buildMaxHeap(data);
    int size = data.size();

    for (int i = size - 1; i >= 1; --i) {
        std::swap(data[i], data[0]);
        size--;
        maxHeapify(data, size, 0);
    }
}

#endif //CORMENBOOK_HEAPSORT_H
