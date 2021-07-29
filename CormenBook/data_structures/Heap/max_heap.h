//
// Created by Emanuel on 29.07.2021.
//

#ifndef CORMENBOOK_MAX_HEAP_H
#define CORMENBOOK_MAX_HEAP_H

#include "heap.h"

template <class T>
class MaxHeap : public Heap<T> {
public:
    MaxHeap(const std::vector<T>& elements);
private:
    void heapify(int index) override;
    void bubbleUp(int index) override;
};

template<class T>
MaxHeap<T>::MaxHeap(const std::vector<T> &elements) : Heap<T>(elements) {
    this->buildHeap();
}

template<class T>
void MaxHeap<T>::heapify(int index) {
    int non_leaves = this->elements.size() - this->leaves();
    while (index < non_leaves) {
        auto children_indices = this->childrenIndices(index);
        int left = children_indices.first, right = children_indices.second, maximum = index;

        if (left < this->elements.size() && this->elements[left] > this->elements[maximum])
            maximum = left;
        if (right < this->elements.size() && this->elements[right] > this->elements[maximum])
            maximum = right;
        std::swap(this->elements[index], this->elements[maximum]);

        if (maximum == index) break;
        index = maximum;
    }
}

template<class T>
void MaxHeap<T>::bubbleUp(int index) {
    int parent = this->parentIndex(index);
    while (index && this->elements[index] > this->elements[parent]) {
        std::swap(this->elements[index], this->elements[parent]);
        index = parent;
    }
}

#endif //CORMENBOOK_MAX_HEAP_H
