//
// Created by Emanuel on 21.08.2021.
//

#ifndef CORMENBOOK_NODE_H
#define CORMENBOOK_NODE_H


template <class K, class D>
struct Node {
    K key;
    D data;

    Node *parent, *left, *right;
    bool color;  // true if black, false else
};


#endif //CORMENBOOK_NODE_H
