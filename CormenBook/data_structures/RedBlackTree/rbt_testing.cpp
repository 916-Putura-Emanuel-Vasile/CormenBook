//
// Created by Emanuel on 21.08.2021.
//

#include "rbt_testing.h"
#include "RedBlackTree.h"

#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

void testRedBlackTree() {
    RedBlackTree<int, std::string> t1;

    t1.insert(6, "a");
    assert(t1.size() == 1);

    t1.insert(4, "b");
    t1.insert(3, "c");
    t1.insert(7, "d");
    t1.insert(10, "e");
    assert(t1.size() == 5);

    std::stringstream stream;
    t1.inorderTraversal(stream);
    assert(stream.str() == "3 4 6 7 10 ");

    std::cout << "...testing red black tree data structure\n";
}
