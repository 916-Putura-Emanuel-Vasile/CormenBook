//
// Created by Emanuel on 28.07.2021.
//

#ifndef CORMENBOOK_HEAP_H
#define CORMENBOOK_HEAP_H

#include <vector>

/*
 * Heap Abstract Class - implements a heap data structure on an array
 */
template<class T>
class Heap {
protected:
    std::vector<T> elements;
public:
    Heap(const std::vector<T>& data);

    void push(const T& element);
    const T& top() const;
    const T& pop();

    inline const std::vector<T>& data() const { return elements; }
    inline int size() const { return elements.size(); }
protected:
    /*
     * Considering that both subtrees are valid heaps, but the value at index i might not respect the heap property, the function transforms
     * the tree rooted in the element at index i in a valid heap
     */
    virtual void heapify(int index) = 0;

    /*
     * Transforms the elements array in a valid heap
     */
    void buildHeap();

    /*
     * Performs a bubble up operation, starting from a given index (i.e., moves the element from the given index upside in the heap until
     * it gets to its right place. Assumes the heap is valid, but for the element at the given index
     */
    virtual void bubbleUp(int index) = 0;

    inline int leaves() const { return (elements.size() + 1) / 2; }
    inline int parentIndex(int index) const { return index / 2; }
    std::pair<int, int> childrenIndices(int index) { return {index * 2, index * 2 + 1}; }
};

template<class T>
void Heap<T>::push(const T &element) {
    elements.push_back(element);
    bubbleUp(elements.size() - 1);
}

template<class T>
Heap<T>::Heap(const std::vector<T> &data) : elements(data) {
    buildHeap();
}

template<class T>
void Heap<T>::buildHeap() {
    for (int i = elements.size() / 2; i >= 0; --i)
        heapify(i);
}

template<class T>
const T &Heap<T>::top() const {
    return elements[0];
}

template<class T>
const T &Heap<T>::pop() {
    auto top_value = top();
    elements[0] = elements[elements.size() - 1];
    elements.erase(elements.end() - 1);

    heapify(0);
    return top_value;
}

#endif //CORMENBOOK_HEAP_H
