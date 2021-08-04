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

    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<int>(v1, 0, v1.size() - 1, 6) == 5);
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<int>(v1, 6) == 5);
    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<int>(v1, 0, v1.size() - 1, 1) == 1);
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<int>(v1, 1) == 1);
    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<int>(v1, 0, v1.size() - 1, 2) == 2);
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<int>(v1, 2) == 2);
    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<int>(v1, 0, v1.size() - 1, 3) == 2);
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<int>(v1, 3) == 2);

    std::vector<int> v2 {17, 20, 2, 18, 123, -4, 41, 201};

    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<int>(v2, 0, v2.size() - 1, 1) == -4);
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<int>(v2, 1) == -4);
    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<int>(v2, 0, v2.size() - 1, v2.size()) == 201);
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<int>(v2, v2.size()) == 201);
    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<int>(v2, 0, v2.size() - 1, v2.size() - 1) == 123);
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<int>(v2, v2.size() - 1) == 123);

    std::vector<std::string> v3 {"salutare", "de", "la", "mare", "ce", "mai", "faceti", "azi", "eu", "bine"};

    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<std::string>(v3, 0, v3.size() - 1, 1) == "azi");
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<std::string>(v3, 1) == "azi");
    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<std::string>(v3, 0, v3.size() - 1, 2) == "bine");
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<std::string>(v3, 2) == "bine");
    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<std::string>(v3, 0, v3.size() - 1, 5) == "eu");
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<std::string>(v3, 5) == "eu");

    std::vector<int> v4 {1, 3, 2, 4, 9, 7, 6, 8, 5};

    assert(SelectionInLinearTime::selectIthSmallerElementRecursively<int>(v4, 0, v4.size() - 1, 5) == 5);
    assert(SelectionInLinearTime::selectIthSmallerElementIteratively<int>(v4, 5) == 5);

    std::cout << "...testing select ith smaller element algorithm\n";
}
