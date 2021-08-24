//
// Created by Emanuel on 21.08.2021.
//

#ifndef CORMENBOOK_REDBLACKTREE_H
#define CORMENBOOK_REDBLACKTREE_H

#include <iostream>

#include "Node.h"

template <class K, class D>
class RedBlackTree {
private:
    Node<K, D> *tree_root;
    Node<K, D> *nil;

    int nodes_number;
public:
    RedBlackTree();
    ~RedBlackTree();
    void inorderTraversal(std::ostream& os) const;
    void insert(const K& key, const D& data);

    int size() const;
    Node<K, D>* root() const;
private:
    void initNode(Node<K, D>* &node, const K& key, const D& data) const;
    void recursiveInorderTraversal(Node<K, D> *subtree_root, std::ostream& os) const;
    void deleteRecursively(Node<K, D> *subtree_root);

    void leftRotate(Node<K, D> *subtree_root);
    void rightRotate(Node<K, D> *subtree_root);

    void insertFixup(Node<K, D> *node);
};

/*
 *  ============================ Implementation ============================
 */

template<class K, class D>
RedBlackTree<K, D>::RedBlackTree() : nil {new Node<K, D>}, nodes_number {0} {
    nil->color = true;
    tree_root = nil;
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
    if (new_root == nil)
        return;

    subtree_root->right = new_root->left;
    new_root->left->parent = subtree_root;
    new_root->parent = subtree_root->parent;

    if (subtree_root->parent == nil)
        tree_root = new_root;
    if (new_root->parent->right == subtree_root)
        new_root->parent->right = new_root;
    else if (new_root->parent->left == subtree_root)
        new_root->parent->left = new_root;

    subtree_root->parent = new_root;
    new_root->left = subtree_root;
}

template<class K, class D>
void RedBlackTree<K, D>::rightRotate(Node<K, D> *subtree_root) {
    auto new_root = subtree_root->left;
    if (new_root == nil)
        return;

    subtree_root->left = new_root->right;
    new_root->right->parent = subtree_root;
    new_root->parent = subtree_root->parent;

    if (subtree_root->parent == nil)
        tree_root = new_root;
    if (new_root->parent->right == subtree_root)
        new_root->parent->right = new_root;
    else if (new_root->parent->left == subtree_root)
        new_root->parent->left = new_root;

    subtree_root->parent = new_root;
    new_root->right = subtree_root;
}

template<class K, class D>
void RedBlackTree<K, D>::inorderTraversal(std::ostream &os) const {
    recursiveInorderTraversal(tree_root, os);
}

template<class K, class D>
void RedBlackTree<K, D>::recursiveInorderTraversal(Node<K, D> *subtree_root, std::ostream& os) const {
    if (subtree_root != nil) {
        recursiveInorderTraversal(subtree_root->left, os);
        os << subtree_root->key << ' ';
        recursiveInorderTraversal(subtree_root->right, os);
    }
}

template<class K, class D>
void RedBlackTree<K, D>::insert(const K &key, const D &data) {
    auto previous_node = nil, current = tree_root;
    while (current != nil) {
        previous_node = current;

        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    initNode(current, key, data);
    current->parent = previous_node;
    current->color = false;

    if (previous_node == nil)
        tree_root = current;
    else if (key < previous_node->key)
        previous_node->left = current;
    else previous_node->right = current;

    insertFixup(current);
    nodes_number++;
}

template<class K, class D>
void RedBlackTree<K, D>::insertFixup(Node<K, D> *node) {
    while (!node->parent->color) {  // while the color of the node's parent is red
        if (node->parent == node->parent->parent->left) {
            auto uncle_node = node->parent->parent->right;
            if (!uncle_node->color) {  // if the color of the uncle node is red, just change the colors of the uncle and of the parent to black, the grandfather's color to red and continue
                node->parent->color = true;
                uncle_node->color = true;
                node->parent->parent->color = false;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }

                node->parent->color = true;
                node->parent->parent->color = false;
                rightRotate(node->parent->parent);
            }
        }
        else {
            auto uncle_node = node->parent->parent->left;
            if (!uncle_node->color) {  // if the color of the uncle node is red, just change the colors of the uncle and of the parent to black, the grandfather's color to red and continue
                node->parent->color = true;
                uncle_node->color = true;
                node->parent->parent->color = false;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }

                node->parent->color = true;
                node->parent->parent->color = false;
                leftRotate(node->parent->parent);
            }
        }
    }

    tree_root->color = true;
}

template<class K, class D>
int RedBlackTree<K, D>::size() const {
    return nodes_number;
}

template<class K, class D>
Node<K, D>* RedBlackTree<K, D>::root() const{
    return tree_root;
}

template<class K, class D>
RedBlackTree<K, D>::~RedBlackTree() {
    deleteRecursively(tree_root);
    delete nil;
}

template<class K, class D>
void RedBlackTree<K, D>::deleteRecursively(Node<K, D> *subtree_root) {
    if (subtree_root != nil) {
        deleteRecursively(subtree_root->left);
        deleteRecursively(subtree_root->right);
        delete subtree_root;
    }
}


#endif //CORMENBOOK_REDBLACKTREE_H
