//
// Created by Emanuel on 03.09.2021.
//

#include "it_testing.h"
#include "IntervalTree.h"

#include <iostream>
#include <sstream>
#include <cassert>

void basicTesting() {
    IntervalTree it;
    it.insert(Interval(2, 3));
    it.insert(Interval(3, 6));
    it.insert(Interval(1, 5));
    it.insert(Interval(7, 8));
    it.insert(Interval(5, 10));

    std::stringstream stream;
    it.inorderTraversal(stream);
    assert(stream.str() == "[1, 5] [2, 3] [3, 6] [5, 10] [7, 8] ");
    assert(it.size() == 5);

    it.remove(Interval(3, 6));
    stream.str("");
    it.inorderTraversal(stream);
    assert(stream.str() == "[1, 5] [2, 3] [5, 10] [7, 8] ");

    it.remove(Interval(1, 5));
    stream.str("");
    it.inorderTraversal(stream);
    assert(stream.str() == "[2, 3] [5, 10] [7, 8] ");
    assert(it.size() == 3);

    it.remove(Interval(7, 8));
    stream.str("");
    it.inorderTraversal(stream);
    assert(stream.str() == "[2, 3] [5, 10] ");
    assert(it.size() == 2);

    it.remove(Interval(2, 3));
    stream.str("");
    it.inorderTraversal(stream);
    assert(stream.str() == "[5, 10] ");
    assert(it.size() == 1);

    it.remove(Interval(5, 10));
    stream.str("");
    it.inorderTraversal(stream);
    assert(stream.str() == "");
    assert(it.size() == 0);
}

void maxPropertyTesting() {
    IntervalTree tree;
    tree.insert(Interval(16, 21));
    assert(tree.root()->high_maximum == 21);

    tree.insert(Interval(25, 30));
    assert(tree.root()->high_maximum == 30);
    tree.insert(Interval(8, 9));
    assert(tree.root()->high_maximum == 30);
    assert(tree.root()->left->high_maximum == 9);
    assert(tree.root()->right->high_maximum == 30);

    tree.insert(Interval(15, 23));
    tree.insert(Interval(5, 8));
    tree.insert(Interval(17, 19));
    tree.insert(Interval(26, 26));

    auto root = tree.root();
    auto root_left = root->left, root_right = root->right;

    // check the root
    assert(root->high_maximum == 30);
    assert(root->key == Interval(16, 21));
    assert(root->color);

    // check the root left child
    assert(root_left->high_maximum == 23);
    assert(root_left->key == Interval(8, 9));
    assert(root_left->color);

    // check the root right child
    assert(root_right->high_maximum == 30);
    assert(root_right->key == Interval(25, 30));
    assert(root_right->color);

    // check the root_left left child
    assert(root_left->left->high_maximum == 8);
    assert(root_left->left->key == Interval(5, 8));
    assert(!root_left->left->color);

    // check the root_left right child
    assert(root_left->right->high_maximum == 23);
    assert(root_left->right->key == Interval(15, 23));
    assert(!root_left->right->color);

    // check the root_right left child
    assert(root_right->left->high_maximum == 19);
    assert(root_right->left->key == Interval(17, 19));
    assert(!root_right->left->color);

    // check the root_right right child
    assert(root_right->right->high_maximum == 26);
    assert(root_right->right->key == Interval(26, 26));
    assert(!root_right->right->color);

    tree.insert(Interval(0, 3));
    tree.insert(Interval(6, 10));
    tree.insert(Interval(19, 20));

    root = tree.root();
    root_left = root->left, root_right = root->right;

    // check the root
    assert(root->high_maximum == 30);
    assert(root->key == Interval(16, 21));
    assert(root->color);

    // check the root left child
    assert(root_left->high_maximum == 23);
    assert(root_left->key == Interval(8, 9));
    assert(!root_left->color);

    // check the root right child
    assert(root_right->high_maximum == 30);
    assert(root_right->key == Interval(25, 30));
    assert(!root_right->color);

    // check the root_left left child
    assert(root_left->left->high_maximum == 10);
    assert(root_left->left->key == Interval(5, 8));
    assert(root_left->left->color);

    // check the root_left right child
    assert(root_left->right->high_maximum == 23);
    assert(root_left->right->key == Interval(15, 23));
    assert(root_left->right->color);

    // check the root_right left child
    assert(root_right->left->high_maximum == 20);
    assert(root_right->left->key == Interval(17, 19));
    assert(root_right->left->color);

    // check the root_right right child
    assert(root_right->right->high_maximum == 26);
    assert(root_right->right->key == Interval(26, 26));
    assert(root_right->right->color);

    // new nodes checking
    assert(root_left->left->left->high_maximum == 3);
    assert(root_left->left->left->key == Interval(0, 3));
    assert(!root_left->left->left->color);

    // new nodes checking
    assert(root_left->left->right->high_maximum == 10);
    assert(root_left->left->right->key == Interval(6, 10));
    assert(!root_left->left->right->color);

    // new nodes checking
    assert(root_right->left->right->high_maximum == 20);
    assert(root_right->left->right->key == Interval(19, 20));
    assert(!root_right->left->right->color);

    // rotations will be needed
    tree.insert(Interval(19, 21));
    root = tree.root();
    root_left = root->left, root_right = root->right;

    // check the root
    assert(root->high_maximum == 30);
    assert(root->key == Interval(16, 21));
    assert(root->color);

    // check the root left child
    assert(root_left->high_maximum == 23);
    assert(root_left->key == Interval(8, 9));
    assert(!root_left->color);

    // check the root right child
    assert(root_right->high_maximum == 30);
    assert(root_right->key == Interval(25, 30));
    assert(!root_right->color);

    // check the root_left left child
    assert(root_left->left->high_maximum == 10);
    assert(root_left->left->key == Interval(5, 8));
    assert(root_left->left->color);

    // check the root_left right child
    assert(root_left->right->high_maximum == 23);
    assert(root_left->right->key == Interval(15, 23));
    assert(root_left->right->color);

    // check the root_right left child
    assert(root_right->left->high_maximum == 21);
    assert(root_right->left->key == Interval(19, 20));
    assert(root_right->left->color);

    // check the root_right right child
    assert(root_right->right->high_maximum == 26);
    assert(root_right->right->key == Interval(26, 26));
    assert(root_right->right->color);

    // new nodes checking
    assert(root_left->left->left->high_maximum == 3);
    assert(root_left->left->left->key == Interval(0, 3));
    assert(!root_left->left->left->color);

    // new nodes checking
    assert(root_left->left->right->high_maximum == 10);
    assert(root_left->left->right->key == Interval(6, 10));
    assert(!root_left->left->right->color);

    // new nodes checking
    assert(root_right->left->right->high_maximum == 21);
    assert(root_right->left->right->key == Interval(19, 21));
    assert(!root_right->left->right->color);

    // new nodes checking
    assert(root_right->left->left->high_maximum == 19);
    assert(root_right->left->left->key == Interval(17, 19));
    assert(!root_right->left->left->color);
}

void testIntervalSearch() {
    IntervalTree tree;

    tree.insert(Interval(16, 21));
    tree.insert(Interval(25, 30));
    tree.insert(Interval(8, 9));
    tree.insert(Interval(15, 23));
    tree.insert(Interval(5, 8));
    tree.insert(Interval(17, 19));
    tree.insert(Interval(26, 26));
    tree.insert(Interval(0, 3));
    tree.insert(Interval(6, 10));
    tree.insert(Interval(19, 20));
    tree.insert(Interval(19, 21));

    assert(tree.intervalSearch(Interval(5, 5))->key == Interval(5, 8));
    assert(tree.intervalSearch(Interval(4, 5))->key == Interval(5, 8));
    assert(tree.intervalSearch(Interval(3, 4))->key == Interval(0, 3));
    assert(tree.intervalSearch(Interval(23, 24))->key == Interval(15, 23));
    assert(tree.intervalSearch(Interval(21, 24))->key == Interval(16, 21));
    assert(tree.intervalSearch(Interval(22, 24))->key == Interval(15, 23));
    assert(tree.intervalSearch(Interval(26, 99))->key == Interval(25, 30));
    assert(tree.intervalSearch(Interval(26, 26))->key == Interval(25, 30));

    assert(tree.intervalSearch(Interval(24, 24)) == nullptr);
    assert(tree.intervalSearch(Interval(4, 4)) == nullptr);
    assert(tree.intervalSearch(Interval(31, 104)) == nullptr);
}

void testIntervalTree() {
    basicTesting();
    maxPropertyTesting();
    testIntervalSearch();

    std::cout << "...testing interval tree data structure\n";
}
