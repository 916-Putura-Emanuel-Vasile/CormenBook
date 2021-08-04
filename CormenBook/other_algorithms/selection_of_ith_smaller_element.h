//
// Created by Emanuel on 03.08.2021.
//

#ifndef CORMENBOOK_SELECTION_OF_ITH_SMALLER_ELEMENT_H
#define CORMENBOOK_SELECTION_OF_ITH_SMALLER_ELEMENT_H

#include <vector>
#include <cstdlib>
#include <iostream>

namespace SelectionInLinearTime {
    template<class T>
    int partition(std::vector<T> &data, int left, int right);

    template<class T>
    int randomizedPartition(std::vector<T> &data, int left, int right);

    template<class T>
    T selectIthSmallerElementRecursively(std::vector<T> &data, int left, int right, int order);

    template <class T>
    T selectIthSmallerElementIteratively(std::vector<T>& data, int order);
}

void testSelectIthSmallerElement();

// ================================================================================

template <class T>
int SelectionInLinearTime::partition(std::vector<T>& data, int left, int right) {
    auto pivot = data[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (data[j] <= pivot) {
            i++;
            std::swap(data[j], data[i]);
        }
    }

    std::swap(data[right], data[i + 1]);
    return i + 1;
}

template <class T>
int SelectionInLinearTime::randomizedPartition(std::vector<T>& data, int left, int right) {
    int random_index = left + rand() % (right - left + 1);
    std::swap(data[random_index], data[right]);
    return SelectionInLinearTime::partition<T>(data, left, right);
}

template<class T>
T SelectionInLinearTime::selectIthSmallerElementRecursively(std::vector<T> &data, int left, int right, int order) {
    if (left == right)
        return data[left];

    int pivot_index = SelectionInLinearTime::randomizedPartition<T>(data, left, right);
    int less_or_equal_than_pivot = pivot_index - left + 1;

    if (less_or_equal_than_pivot == order)
        return data[pivot_index];

    if (order < less_or_equal_than_pivot)
        return SelectionInLinearTime::selectIthSmallerElementRecursively<T>(data, left, pivot_index - 1, order);
    else
        return SelectionInLinearTime::selectIthSmallerElementRecursively<T>(data, pivot_index + 1, right,
                                                                            order - less_or_equal_than_pivot);
}

template<class T>
T SelectionInLinearTime::selectIthSmallerElementIteratively(std::vector<T> &data, int order) {
    int left = 0, right = data.size() - 1;

    while (true) {
        if (left == right)
            return data[left];

        int pivot_index = SelectionInLinearTime::randomizedPartition<T>(data, left, right);
        int less_or_equal_than_pivot = pivot_index  - left + 1;

        if (less_or_equal_than_pivot == order)
            return data[pivot_index];

        if (less_or_equal_than_pivot < order) {
            left = pivot_index + 1;
            order -= less_or_equal_than_pivot;
        }
        else
            right = pivot_index - 1;
    }
}

#endif //CORMENBOOK_SELECTION_OF_ITH_SMALLER_ELEMENT_H
