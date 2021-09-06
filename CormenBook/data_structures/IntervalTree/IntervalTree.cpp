//
// Created by Emanuel on 03.09.2021.
//

#include "IntervalTree.h"

void IntervalTree::insert(const Interval &interval) {
    auto previous_node = nil, current = tree_root;
    while (current != nil) {
        current->high_maximum = std::max(current->high_maximum, interval.high);
        previous_node = current;

        if (interval < current->key)
            current = current->left;
        else
            current = current->right;
    }

    initNode(current, interval);
    current->parent = previous_node;
    current->color = false;

    if (previous_node == nil)
        tree_root = current;
    else if (interval < previous_node->key)
        previous_node->left = current;
    else previous_node->right = current;

    insertFixup(current);
    nodes_number++;
}

void IntervalTree::remove(const Interval &interval) {
    auto node = search(interval);
    if (node == nil)
        throw RedBlackTreeException("The key to be removed was not found.");

    auto changing_node = node;  // if node has less than two children, than changing_node is node; else, it is the successor of node
    auto replace_node = nil;    // the node that replaces the deleted/moved one (i.e., changing_node)
    auto changing_node_original_color = changing_node->color;  // the original color of the changing node

    if (node->right == nil) {
        replace_node = node->left;
        transplant(node, node->left);
    }
    else if (node->left == nil) {
        replace_node = node->right;
        transplant(node, node->right);
    }
    else {
        changing_node = subtree_minimum(node->right);
        changing_node_original_color = changing_node->color;
        replace_node = changing_node->right;  // the minimum only has a right child

        transplant(changing_node, changing_node->right);
        changing_node->right = node->right;
        changing_node->right->parent = changing_node;
        transplant(node, changing_node);
        changing_node->left = node->left;
        changing_node->left->parent = changing_node;
        changing_node->color = node->color;
    }

    // changing_node always has at most one child
    auto replace_node_copy = replace_node;
    if (changing_node != node) {  // two children case
        replace_node = replace_node->parent;
        while (replace_node != changing_node) {
            replace_node->high_maximum = getMaximumFromSubtree(replace_node);
            replace_node = replace_node->parent;
        }
    }

    while (changing_node != nil) {
        changing_node->high_maximum = getMaximumFromSubtree(changing_node);
        changing_node = changing_node->parent;
    }

    // only if the original color of changing_node was black
    if (changing_node_original_color)
        deleteFixup(replace_node_copy);
    nodes_number--;
    delete node;
}

void IntervalTree::leftRotate(IntervalTreeNode *subtree_root) {
    auto new_root = subtree_root->right;
    if (new_root == nil)
        return;

    new_root->high_maximum = subtree_root->high_maximum;
    subtree_root->high_maximum = subtree_root->key.high;
    if (subtree_root->left != nil)
        subtree_root->high_maximum = std::max(subtree_root->key.high, subtree_root->left->high_maximum);
    if (new_root->left != nil)
        subtree_root->high_maximum = std::max(subtree_root->high_maximum, new_root->left->high_maximum);
    RedBlackTree::leftRotate(subtree_root);
}

void IntervalTree::rightRotate(IntervalTreeNode *subtree_root) {
    auto new_root = subtree_root->left;
    if (new_root == nil)
        return;

    new_root->high_maximum = subtree_root->high_maximum;
    subtree_root->high_maximum = subtree_root->key.high;
    if (subtree_root->right != nil)
        subtree_root->high_maximum = std::max(subtree_root->key.high, subtree_root->right->high_maximum);
    if (new_root->right != nil)
        subtree_root->high_maximum = std::max(subtree_root->high_maximum, new_root->right->high_maximum);
    RedBlackTree::rightRotate(subtree_root);
}

int IntervalTree::getMaximumFromSubtree(IntervalTreeNode *subtree_root) const {
    if (subtree_root == nil)
        throw RedBlackTreeException("The given interval tree node is not valid.");

    int maximum = subtree_root->key.high;
    if (subtree_root->left != nil && subtree_root->left->high_maximum > maximum)
        maximum = subtree_root->left->high_maximum;
    if (subtree_root->right != nil && subtree_root->right->high_maximum > maximum)
        maximum = subtree_root->right->high_maximum;
    return maximum;
}

void IntervalTree::changeTree(IntervalTreeNode *new_root) {
    deleteRecursively(tree_root);
    tree_root = new_root;
}

IntervalTreeNode *IntervalTree::getNil() const {
    return nil;
}

void IntervalTree::initNode(IntervalTreeNode *&node, const Interval &interval) const {
    RedBlackTree::initNode(node, interval);
    node->high_maximum = node->key.high;

}
