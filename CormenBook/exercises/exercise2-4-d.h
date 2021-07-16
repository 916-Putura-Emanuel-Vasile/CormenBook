//
// Created by Emanuel on 14.07.2021.
//

#ifndef CORMENBOOK_EXERCISE2_4_D_H
#define CORMENBOOK_EXERCISE2_4_D_H

#include <vector>
#include <algorithm>

/*
 * Give an algorithm that determines the number of inversions in any permutation on n elements in‚ O(n lg n) worst-case time.
 * Hint: modify merge sort
 */

int mergeAndCountInversions(std::vector<int>& data, int begin, int limit, int end);
int countInversions(std::vector<int>& data, int begin, int end);

void testCountInversions();

#endif //CORMENBOOK_EXERCISE2_4_D_H
