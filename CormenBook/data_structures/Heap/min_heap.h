//
// Created by Emanuel on 29.07.2021.
//

#ifndef CORMENBOOK_MIN_HEAP_H
#define CORMENBOOK_MIN_HEAP_H

#include "heap.h"

template <class T>
class MinHeap : public Heap<T> {
public:
    MinHeap(const std::vector<T>& elements);
private:
    void heapify(int index) override;
    void bubbleUp(int index) override;
};

template<class T>
MinHeap<T>::MinHeap(const std::vector<T>& elements) : Heap<T>(elements) {
    this->buildHeap();
}

template<class T>
void MinHeap<T>::heapify(int index) {
    int non_leaves = this->elements.size() - this->leaves();
    while (index < non_leaves) {
        auto children_indices = this->childrenIndices(index);
        int left = children_indices.first, right = children_indices.second, minimum = index;

        if (left < this->elements.size() && this->elements[left] < this->elements[minimum])
            minimum = left;
        if (right < this->elements.size() && this->elements[right] < this->elements[minimum])
            minimum = right;
        std::swap(this->elements[index], this->elements[minimum]);

        if (minimum == index) break;
        index = minimum;
    }
}

template<class T>
void MinHeap<T>::bubbleUp(int index) {
    int parent = this->parentIndex(index);
    while (index && this->elements[index] < this->elements[parent]) {
        std::swap(this->elements[index], this->elements[parent]);
        index = parent;
    }
}

#endif //CORMENBOOK_MIN_HEAP_H
