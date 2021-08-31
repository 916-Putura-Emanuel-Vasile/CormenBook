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
    assert(t1.maximum().first == 6 && t1.maximum().second == "a");
    assert(t1.minimum().first == 6 && t1.minimum().second == "a");

    t1.insert(4, "b");
    t1.insert(7, "c");

    auto root = t1.root();
    assert(root->key == 6);
    assert(root->left->key == 4);
    assert(root->right->key == 7);

    assert(!root->left->color && !root->right->color);
    t1.insert(7, "d");
    assert(root->left->color && root->right->color);  // red uncle case

    t1.insert(10, "e");  // black uncle, right-right case
    assert(t1.size() == 5);

    t1.insert(3, "f");
    assert(t1.size() == 6);
    assert(t1.minimum().first == 3 && t1.minimum().second == "f");
    assert(t1.maximum().first == 10 && t1.maximum().second == "e");

    root = t1.root();
    assert(root->key == 6 && root->color);
    assert(root->left->key == 4 && root->left->color);
    assert(root->left->left->key == 3 && !root->left->left->color);
    assert(root->right->key == 7 && root->right->color);
    assert(root->right->left->key == 7 && !root->right->left->color);
    assert(root->right->right->key == 10 && !root->right->right->color);

    std::stringstream stream;
    t1.inorderTraversal(stream);
    assert(stream.str() == "3 4 6 7 7 10 ");

    t1.remove(7);
    assert(t1.size() == 5);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "3 4 6 7 10 ");

    t1.remove(3);
    assert(t1.size() == 4);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "4 6 7 10 ");

    t1.remove(10);
    assert(t1.size() == 3);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "4 6 7 ");

    try {
        t1.remove(10);
        assert(false);
    }
    catch (const RedBlackTreeException& exception) {
        assert(exception.message() == "The key to be removed was not found.");
    }

    t1.remove(6);
    assert(t1.size() == 2);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "4 7 ");

    t1.remove(4);
    assert(t1.size() == 1);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "7 ");
    assert(t1.root()->key == 7);

    t1.remove(7);
    assert(t1.size() == 0);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "");

    std::cout << "...testing red black tree data structure\n";
}
