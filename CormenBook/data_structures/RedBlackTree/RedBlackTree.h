//
// Created by Emanuel on 21.08.2021.
//

#ifndef CORMENBOOK_REDBLACKTREE_H
#define CORMENBOOK_REDBLACKTREE_H

#include <iostream>
#include <exception>
#include <string>

#include "Node.h"

class RedBlackTreeException : public std::exception {
private:
    std::string error_message;
public:
    RedBlackTreeException(const std::string& error_message);
    const std::string& message() const;
};

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
    void remove(const K& key);

    Node<K, D>* search(const K& key) const;
    std::pair<K, D> minimum() const;
    std::pair<K, D> maximum() const;

    int size() const;
    Node<K, D>* root() const;
private:
    void initNode(Node<K, D>* &node, const K& key, const D& data) const;
    void recursiveInorderTraversal(Node<K, D> *subtree_root, std::ostream& os) const;
    void deleteRecursively(Node<K, D> *subtree_root);

    void leftRotate(Node<K, D> *subtree_root);
    void rightRotate(Node<K, D> *subtree_root);
    void transplant(Node<K, D> *initial_node, Node<K, D> *new_node);

    Node<K, D>* subtree_minimum(Node<K, D> *root) const;
    Node<K, D>* subtree_maximum(Node<K, D> *root) const;

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

template<class K, class D>
void RedBlackTree<K, D>::transplant(Node<K, D> *initial_node, Node<K, D> *new_node) {
    if (tree_root == initial_node)
        tree_root = new_node;
    else if (initial_node == initial_node->parent->right)
        initial_node->parent->right = new_node;
    else
        initial_node->parent->left = new_node;

    new_node->parent = initial_node->parent;
    delete initial_node;
}

template<class K, class D>
void RedBlackTree<K, D>::remove(const K &key) {
    auto node = search(key);
    if (node == nil)
        throw RedBlackTreeException("The key to be removed was not found.");



}

template<class K, class D>
Node<K, D> *RedBlackTree<K, D>::search(const K& key) const {
    auto current = tree_root;
    while (current != nil && current->key != key) {
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

template<class K, class D>
std::pair<K, D> RedBlackTree<K, D>::minimum() const {
    auto minimum = subtree_minimum(tree_root);
    return std::make_pair(minimum->key, minimum->data);
}

template<class K, class D>
std::pair<K, D> RedBlackTree<K, D>::maximum() const {
    auto maximum = subtree_maximum(tree_root);
    return std::make_pair(maximum->key, maximum->data);
}

template<class K, class D>
Node<K, D>* RedBlackTree<K, D>::subtree_minimum(Node<K, D> *root) const {
    auto previous = root;
    while (root != nil) {
        previous = root;
        root = root->left;
    }
    return previous;
}

template<class K, class D>
Node<K, D>* RedBlackTree<K, D>::subtree_maximum(Node<K, D> *root) const {
    auto previous = root;
    while (root != nil) {
        previous = root;
        root = root->right;
    }
    return previous;
}


#endif //CORMENBOOK_REDBLACKTREE_H
