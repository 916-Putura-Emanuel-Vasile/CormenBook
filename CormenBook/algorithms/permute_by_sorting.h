//
// Created by Emanuel on 27.07.2021.
//

#ifndef CORMENBOOK_PERMUTE_BY_SORTING_H
#define CORMENBOOK_PERMUTE_BY_SORTING_H

#include <vector>

template <class T>
void permuteBySorting(std::vector<T>& data);

template<class T>
void permuteBySorting(std::vector<T> &data) {
    std::vector<T> priorities (data.size());
    for (int i = 0; i < data.size(); ++i)
        priorities[i] = rand();
    // sort data, using the priorities as keys
}

#endif //CORMENBOOK_PERMUTE_BY_SORTING_H
