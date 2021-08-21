#include "other_algorithms/polynomial_eval_horner_rule.h"
#include "other_algorithms/maximum_subarray_problem.h"
#include "exercises/exercise2-4-d.h"
#include "other_algorithms/permutations.h"
#include "sorting_algorithms/heapsort.h"
#include "data_structures/Heap/testing.h"
#include "sorting_algorithms/quicksort.h"
#include "sorting_algorithms/randomized_quicksort.h"
#include "sorting_algorithms/counting_sort.h"
#include "sorting_algorithms/radix_sort.h"
#include "other_algorithms/selection_of_ith_smaller_element.h"
#include "data_structures/RedBlackTree/rbt_testing.h"

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
    testHeapSort();
    testMaxHeap();
    testQuickSort();
    testRandomizedQuickSort();
    testCountingSort();
    testRadixSort();
    testSelectIthSmallerElement();
    testRedBlackTree();

    std::cout << "All tests done!\n\n";
}
