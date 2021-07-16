//
// Created by Emanuel on 16.07.2021.
//

#include "maximum_subarray_problem.h"
#include <cassert>

std::tuple<int, int, int> findMaximumSubarray(const std::vector<int> &array, int begin, int end) {
    int max_sum = -0x3f3f3f3f;  // at each current index i it represents the max sum in subarray array[0..i]
    int current = -0x3f3f3f3f;  // at each current index i it represents the max sum from subarray array[0..i], containing element array[i]
    int left = 0, right = 0;    // left and right indices for the maximum subarray

    for (int i = 0; i < array.size(); ++i) {
        if (current + array[i] > array[i]) {
            current = current + array[i];
        }
        else {
            current = array[i];
            left = i;
        }

        if (current >= max_sum) {
            max_sum = current;
            right = i;
        }
    }

    return std::tuple<int, int, int>{left, right, max_sum};
}

void testFindMaximumSubarray() {
    std::vector<int> v1 {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    auto r1 = findMaximumSubarray(v1, 0, v1.size() - 1);

    assert(std::get<0>(r1) == 7);
    assert(std::get<1>(r1) == 10);
    assert(std::get<2>(r1) == 43);

    std::vector<int> v2 {2, 5, -10, 3, 2, 2, -11};
    auto r2 = findMaximumSubarray(v2, 0, v2.size() - 1);

    assert(std::get<0>(r2) == 3);
    assert(std::get<1>(r2) == 5);
    assert(std::get<2>(r2) == 7);
}
