//
// Created by Emanuel on 02.08.2021.
//

#include <cassert>
#include <iostream>
#include <algorithm>

#include "radix_sort.h"

void modifiedCountingSort(std::vector<int> &data, int digit_modulo_order, int max_no) {
    auto getDigit = [](int number, int digit_modulo_order) {
        return (number / digit_modulo_order) % 10;
    };

    std::vector<int> counter (max_no + 1, 0);
    std::vector<int> result (data.size());

    for (const auto& el : data)
        counter[getDigit(el, digit_modulo_order)]++;

    for (int i = 1; i < counter.size(); ++i)
        counter[i] += counter[i - 1];

    for (int i = data.size() - 1; i >= 0; --i) {
        result[counter[getDigit(data[i], digit_modulo_order)] - 1] = data[i];
        counter[getDigit(data[i], digit_modulo_order)]--;
    }

    std::copy(result.begin(), result.end(), data.begin());
}

void radixSort(std::vector<int> &data, int digits_no) {
    int digit_modulo_order = 1;
    for (int d = 1; d <= digits_no; ++d) {
        modifiedCountingSort(data, digit_modulo_order);
        digit_modulo_order *= 10;
    }
}

void testRadixSort() {
    std::vector<int> v1 {5, 13, 2, 25, 7, 17, 20, 8, 4};
    std::vector<int> r1 {2, 4, 5, 7, 8, 13, 17, 20, 25};

    radixSort(v1, 2);
    assert(v1 == r1);

    std::vector<int> v2 {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> r2 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    radixSort(v2, 1);
    assert(v2 == r2);

    std::vector<int> v3 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> r3 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    radixSort(v3, 1);
    assert(v3 == r3);

    std::vector<int> v4 {2, 5, 3, 0, 2, 3, 0, 3};
    std::vector<int> r4 {0, 0, 2, 2, 3, 3, 3, 5};

    radixSort(v4, 1);
    assert(v4 == r4);

    std::vector<int> v5 {329, 457, 657, 839, 436, 720, 355};
    std::vector<int> r5 {329, 355, 436, 457, 657, 720, 839};

    radixSort(v5, 3);
    assert(v5 == r5);

    std::cout << "...testing counting sort algorithm\n";
}
