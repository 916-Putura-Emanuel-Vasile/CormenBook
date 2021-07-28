//
// Created by Emanuel on 14.07.2021.
//

#include <iostream>
#include <iterator>
#include <cassert>
#include "exercise2-4-d.h"

int mergeAndCountInversions(std::vector<int> &data, int begin, int limit, int end) {
    std::vector<int> left, right;
    std::copy(data.begin() + begin, data.begin() + limit + 1, std::back_inserter(left));
    std::copy(data.begin() + limit + 1, data.begin() + end + 1, std::back_inserter(right));

    int i = 0, j = 0, k = begin, inversions = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            data[k] = left[i];
            i++;
        }
        else {
            data[k] = right[j];
            j++;
            inversions += left.size() - i;
        }
        k++;
    }

    while (i < left.size()) {
        data[k] = left[i];
        i++; k++;
    }

    while (j < right.size()) {
        data[k] = right[j];
        j++; k++;
    }

    return inversions;
}

int countInversions(std::vector<int> &data, int begin, int end) {
    int middle = (begin + end) / 2;
    if (begin == end) return 0;
    return countInversions(data, begin, middle) + countInversions(data, middle + 1, end) + mergeAndCountInversions(data, begin, middle, end);
}

void testCountInversions() {
    std::cout << "...testing algorithm for counting inversions\n";

    std::vector<int> v1 {2, 3, 8, 6, 1};
    assert(countInversions(v1, 0, v1.size() - 1) == 5);

    std::vector<int> v2 {2, 3, 8, 1, 6};
    assert(mergeAndCountInversions(v2, 0, 2, 4) == 4);

    std::vector<int> v3 {5, 8, 1, 0, 3, 9};
    assert(countInversions(v3, 0, v3.size() - 1) == 7);

    std::vector<int> v4 {5, 8, 1, 0, 3, 9};
    assert(countInversions(v4, 0, v4.size() - 1) == 7);

    std::vector<int> v5 {5, 8, 1, 0, 3, 9, -4, 2, 8, 3, 1, 10};
    assert(countInversions(v5, 0, v5.size() - 1) == 29);
}
