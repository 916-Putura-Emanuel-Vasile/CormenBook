//
// Created by Emanuel on 28.07.2021.
//

#include "heapsort.h"

#include <iostream>
#include <cassert>

void testHeapsort() {
    std::vector<int> v1 {5, 13, 2, 25, 7, 17, 20, 8, 4};
    std::vector<int> r1 {2, 4, 5, 7, 8, 13, 17, 20, 25};

    heapsort(v1);
    assert(v1 == r1);

    std::vector<int> v2 {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> r2 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    heapsort(v2);
    assert(v2 == r2);

    std::vector<int> v3 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> r3 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    heapsort(v3);
    assert(v3 == r3);

    std::vector<std::string> v4 {"dreptunghiul", "este", "un", "paralelogram", "cu", "un", "unghi", "drept"};
    std::vector<std::string> r4 {"cu", "drept", "dreptunghiul", "este", "paralelogram", "un", "un", "unghi"};

    heapsort(v4);
    assert(v4 == r4);

    std::cout << "...testing heapsort algorithm\n";
}
