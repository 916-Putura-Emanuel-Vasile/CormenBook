#include "other_algorithms/polynomial_eval_horner_rule.h"
#include "other_algorithms/maximum_subarray_problem.h"
#include "exercises/exercise2-4-d.h"
#include "other_algorithms/permutations.h"
#include "sorting_algorithms/heapsort.h"
#include "data_structures/Heap/testing.h"

#include <iostream>

void test();

int main() {
    test();
    return 0;
}

void test() {
    testPolynomialHornerEvaluation();
    testCountInversions();
    testFindMaximumSubarray();
    testPermuteByPriorityQueue();
    testRandomizeInPlace();
    testHeapsort();
    testMaxHeap();

    std::cout << "All tests done!\n\n";
}
