//
// Created by Emanuel on 02.08.2021.
//

#include <cassert>
#include <iostream>
#include <algorithm>

#include "counting_sort.h"

void countingSort(std::vector<int> &data, int max_limit) {
    std::vector<int> counter (max_limit + 1, 0);
    std::vector<int> result (data.size());

    for (int i = 0; i < data.size(); ++i)
        counter[data[i]]++;

    for (int i = 1; i <= max_limit; ++i)
        counter[i] += counter[i - 1];

    // iterate in reverse order such that stability is preserved
    for (int i = data.size() - 1; i >= 0; --i) {
        result[counter[data[i]] - 1] = data[i];
        counter[data[i]]--;
    }

    std::copy(result.begin(), result.end(), data.begin());
}

void testCountingSort() {
    std::vector<int> v1 {5, 13, 2, 25, 7, 17, 20, 8, 4};
    std::vector<int> r1 {2, 4, 5, 7, 8, 13, 17, 20, 25};

    countingSort(v1, 25);
    assert(v1 == r1);

    std::vector<int> v2 {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> r2 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    countingSort(v2, v2.size());
    assert(v2 == r2);

    std::vector<int> v3 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> r3 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    countingSort(v3, v3.size());
    assert(v3 == r3);

    std::vector<int> v4 {2, 5, 3, 0, 2, 3, 0, 3};
    std::vector<int> r4 {0, 0, 2, 2, 3, 3, 3, 5};

    countingSort(v4, v4.size());
    assert(v4 == r4);

    std::cout << "...testing counting sort algorithm\n";
}
