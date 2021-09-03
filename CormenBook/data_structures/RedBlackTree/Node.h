//
// Created by Emanuel on 21.08.2021.
//

#ifndef CORMENBOOK_NODE_H
#define CORMENBOOK_NODE_H


template <class K>
class Node {
private:
    K key;                        // key of the node
    Node *parent, *left, *right;  // links in the tree
    bool color;                   // true if black, false else
public:
    template <class Key, class Node> friend class RedBlackTree;

    inline const K& getKey() const { return key; }
    inline Node* getParent() const { return parent; }
    inline Node* getLeftChild() const { return left; }
    inline Node* getRightChild() const { return right; }
    inline bool getColor() const { return color; }
};


#endif //CORMENBOOK_NODE_H
