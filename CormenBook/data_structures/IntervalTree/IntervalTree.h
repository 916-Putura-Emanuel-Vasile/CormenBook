//
// Created by Emanuel on 03.09.2021.
//

#ifndef CORMENBOOK_INTERVALTREE_H
#define CORMENBOOK_INTERVALTREE_H

#include "Interval.h"
#include "IntervalTreeNode.h"
#include "../RedBlackTree/RedBlackTree.h"

class IntervalTree : public RedBlackTree<Interval, IntervalTreeNode> {
public:
    void insert(const Interval& interval) override;
    void remove(const Interval& interval) override;
    IntervalTreeNode *intervalSearch(const Interval& interval) const;
private:
    void leftRotate(IntervalTreeNode *subtree_root) override;
    void rightRotate(IntervalTreeNode *subtree_root) override;

    int getMaximumFromSubtree(IntervalTreeNode *subtree_root) const;
    void initNode(IntervalTreeNode* &node, const Interval& interval) const override;
};

#endif //CORMENBOOK_INTERVALTREE_H
