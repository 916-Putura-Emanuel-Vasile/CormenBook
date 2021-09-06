//
// Created by Emanuel on 03.09.2021.
//

#ifndef CORMENBOOK_INTERVALTREENODE_H
#define CORMENBOOK_INTERVALTREENODE_H

#include "../RedBlackTree/Node.h"
#include "Interval.h"

class IntervalTree;

class IntervalTreeNode {
private:
    Interval key;                        // key of the node
    IntervalTreeNode *parent, *left, *right;  // links in the tree
    bool color;                   // true if black, false else
    int high_maximum;  // maximum high limit of the intervals from the (sub)tree rooted in this node
public:
    IntervalTreeNode();
    inline int getHighMaximum() const { return high_maximum; }
private:
    template <class Key, class Node> friend class RedBlackTree;
    friend class IntervalTree;

    void friend maxPropertyTesting();
    void friend testIntervalSearch();
};


#endif //CORMENBOOK_INTERVALTREENODE_H
