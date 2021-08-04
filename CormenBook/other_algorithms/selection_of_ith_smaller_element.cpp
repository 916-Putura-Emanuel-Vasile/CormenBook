//
// Created by Emanuel on 03.08.2021.
//

#include "selection_of_ith_smaller_element.h"

#include <vector>
#include <string>
#include <cassert>
#include <iostream>

void testSelectIthSmallerElement() {
    std::vector<int> v1 {1, 3, 5, 4, 2, 9, 7, 6, 8, 2};

    assert(SelectionInLinearTime::selectIthSmallerElement<int>(v1, 0, v1.size() - 1, 6));
    assert(SelectionInLinearTime::selectIthSmallerElement<int>(v1, 0, v1.size() - 1, 1) == 1);
    assert(SelectionInLinearTime::selectIthSmallerElement<int>(v1, 0, v1.size() - 1, 2) == 2);
    assert(SelectionInLinearTime::selectIthSmallerElement<int>(v1, 0, v1.size() - 1, 3) == 2);

    std::vector<int> v2 {17, 20, 2, 18, 123, -4, 41, 201};

    assert(SelectionInLinearTime::selectIthSmallerElement<int>(v2, 0, v2.size() - 1, 1) == -4);
    assert(SelectionInLinearTime::selectIthSmallerElement<int>(v2, 0, v2.size() - 1, v2.size()) == 201);
    assert(SelectionInLinearTime::selectIthSmallerElement<int>(v2, 0, v2.size() - 1, v2.size() - 1) == 123);

    std::vector<std::string> v3 {"salutare", "de", "la", "mare", "ce", "mai", "faceti", "azi", "eu", "bine"};

    assert(SelectionInLinearTime::selectIthSmallerElement<std::string>(v3, 0, v3.size() - 1, 1) == "azi");
    assert(SelectionInLinearTime::selectIthSmallerElement<std::string>(v3, 0, v3.size() - 1, 2) == "bine");
    assert(SelectionInLinearTime::selectIthSmallerElement<std::string>(v3, 0, v3.size() - 1, 1) == "azi");

    std::vector<int> v4 {1, 3, 2, 4, 9, 7, 6, 8, 5};
    assert(SelectionInLinearTime::selectIthSmallerElement<int>(v4, 0, v4.size() - 1, 5));

    std::cout << "...testing select ith smaller element algorithm\n";
}
