//
// Created by Emanuel on 21.08.2021.
//

#ifndef CORMENBOOK_REDBLACKTREE_H
#define CORMENBOOK_REDBLACKTREE_H

#include "Node.h"

template <class K, class D>
class RedBlackTree {
private:
    Node<K, D> *root;
    Node<K, D> *nil;

    int nodes_number;
public:
    RedBlackTree();
private:
    void initNode(Node<K, D>* &node, const K& key, const D& data) const;

    void leftRotate(Node<K, D> *subtree_root);
    void rightRotate(Node<K, D> *subtree_root);
};

/*
 *  ============================ Implementation ============================
 */

template<class K, class D>
RedBlackTree<K, D>::RedBlackTree() : nil {new Node<K, D>}, root {nil}, nodes_number {0} {
}

template<class K, class D>
void RedBlackTree<K, D>::initNode(Node<K, D>* &node, const K& key, const D& data) const {
    node = new Node<K, D>;
    node->key = key;
    node->data = data;
    node->parent = nil;
    node->right = nil;
    node->left = nil;
    node->color = true;
}

template<class K, class D>
void RedBlackTree<K, D>::leftRotate(Node<K, D> *subtree_root) {
    auto new_root = subtree_root->right;
    subtree_root->right = new_root->left;
    new_root->left->parent = subtree_root;
    new_root->parent = subtree_root->parent;
    subtree_root->parent = new_root;

    if (subtree_root->parent == nil)
        root = new_root;
    if (new_root->parent->right == subtree_root)
        new_root->parent->right = new_root;
    else if (new_root->parent->left == subtree_root)
        new_root->parent->left = new_root;
}

template<class K, class D>
void RedBlackTree<K, D>::rightRotate(Node<K, D> *subtree_root) {
    auto new_root = subtree_root->left;
    subtree_root->left = new_root->right;
    new_root->right->parent = subtree_root;
    new_root->parent = subtree_root->parent;
    subtree_root->parent = new_root;

    if (subtree_root->parent == nil)
        root = new_root;
    if (new_root->parent->right == subtree_root)
        new_root->parent->right = new_root;
    else if (new_root->parent->left == subtree_root)
        new_root->parent->left = new_root;
}


#endif //CORMENBOOK_REDBLACKTREE_H
