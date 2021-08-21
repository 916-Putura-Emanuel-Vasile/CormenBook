//
// Created by Emanuel on 29.07.2021.
//

#include "testing.h"
#include "max_heap.h"

#include <vector>
#include <iostream>
#include <cassert>

void testMaxHeap() {
    std::vector<int> v1 {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    std::vector<int> result {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    MaxHeap<int> h1 {v1};

    assert (h1.data() == result);
    assert(h1.top() == 16);
    assert(h1.pop() == 16);
    assert(h1.size() == 9);

    result = {14, 8, 10, 4, 7, 9, 3, 2, 1};
    assert(h1.data() == result);

    h1.push(8);
    result = {14, 8, 10, 4, 8, 9, 3, 2, 1, 7};
    assert(h1.data() == result);
    assert(h1.size() == 10);
    assert(h1.top() == 14);

    std::cout << "...testing max heap data structure\n";
}
