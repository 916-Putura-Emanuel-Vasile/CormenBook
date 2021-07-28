//
// Created by Emanuel on 27.07.2021.
//

#include "permutations.h"

#include <cassert>

void testPermuteByPriorityQueue() {
    std::cout << "...testing permutation by priority queue algorithm\n";

    std::vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<bool> b1 (v1.size());
    permuteByPriorityQueue(v1);
//    printVector(v1);
}

void testRandomizeInPlace() {
    std::cout << "...testing permutation by randomizing in-place algorithm\n";

    std::vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<bool> b1 (v1.size());
    permuteByPriorityQueue(v1);
//    printVector(v1);
}
