//
// Created by Emanuel on 16.07.2021.
//

#ifndef CORMENBOOK_MAXIMUM_SUBARRAY_PROBLEM_H
#define CORMENBOOK_MAXIMUM_SUBARRAY_PROBLEM_H

#include <vector>
#include <tuple>

/*
 * Linear algorithm for finding one subarray of maximum sum of a given array
 */
std::tuple<int, int, int> findMaximumSubarray(const std::vector<int>& array, int begin, int end);

void testFindMaximumSubarray();

#endif //CORMENBOOK_MAXIMUM_SUBARRAY_PROBLEM_H
