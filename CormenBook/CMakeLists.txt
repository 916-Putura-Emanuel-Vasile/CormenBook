cmake_minimum_required(VERSION 3.17)
project(CormenBook)

set(CMAKE_CXX_STANDARD 14)

add_executable(CormenBook main.cpp other_algorithms/polynomial_eval_horner_rule.h other_algorithms/polynomial_eval_horner_rule.cpp exercises/exercise2-4-d.cpp exercises/exercise2-4-d.h other_algorithms/maximum_subarray_problem.cpp other_algorithms/maximum_subarray_problem.h other_algorithms/permutations.cpp other_algorithms/permutations.h sorting_algorithms/heapsort.cpp sorting_algorithms/heapsort.h data_structures/Heap/heap.cpp data_structures/Heap/heap.h data_structures/Heap/max_heap.cpp data_structures/Heap/max_heap.h data_structures/Heap/testing.cpp data_structures/Heap/testing.h data_structures/Heap/min_heap.cpp data_structures/Heap/min_heap.h sorting_algorithms/quicksort.cpp sorting_algorithms/quicksort.h sorting_algorithms/randomized_quicksort.cpp sorting_algorithms/randomized_quicksort.h)