//
// Created by Emanuel on 21.08.2021.
//

#ifndef CORMENBOOK_NODE_H
#define CORMENBOOK_NODE_H


template <class K>
struct Node {
    K key;                        // key of the node

    Node *parent, *left, *right;  // links in the tree
    bool color;                   // true if black, false else
};


#endif //CORMENBOOK_NODE_H
