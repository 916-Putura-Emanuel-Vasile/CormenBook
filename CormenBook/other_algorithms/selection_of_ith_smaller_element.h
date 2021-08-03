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
    T selectIthSmallerElement(std::vector<T> &data, int left, int right, int order);
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
    std::cout << left << ' ' << right << ' ' << right - left + 1 << '\n';
    int random_index = left + rand() % (right - left + 1);
    std::swap(data[random_index], data[right]);
    return SelectionInLinearTime::partition<T>(data, left, right);
}

template<class T>
T SelectionInLinearTime::selectIthSmallerElement(std::vector<T> &data, int left, int right, int order) {
    if (left == right)
        return data[left];

    int pivot_index = SelectionInLinearTime::randomizedPartition<T>(data, left, right);
    int less_than_pivot = pivot_index - left + 1;

    if (pivot_index == order - 1)
        return data[pivot_index];

    std::cout << "AAA " << order << ' ' << less_than_pivot << '\n';
    if (order < less_than_pivot)
        return SelectionInLinearTime::selectIthSmallerElement<T>(data, left, pivot_index - 1, order);
    else
        return SelectionInLinearTime::selectIthSmallerElement<T>(data, pivot_index + 1, right, order - pivot_index - 1);
}

#endif //CORMENBOOK_SELECTION_OF_ITH_SMALLER_ELEMENT_H
