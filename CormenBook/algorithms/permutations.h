//
// Created by Emanuel on 27.07.2021.
//

#ifndef CORMENBOOK_PERMUTATIONS_H
#define CORMENBOOK_PERMUTATIONS_H

#include <iostream>
#include <vector>
#include <queue>
#include <time.h>

template <class T>
void printVector(const std::vector<T>& data);

template <class T>
void randomizeInPlace(std::vector<T>& data);

template <class T>
void permuteBySorting(std::vector<T>& data);

template <class T>
void permuteByPriorityQueue(std::vector<T>& data);

void testPermuteByPriorityQueue();
void testRandomizeInPlace();

template<class T>
void permuteBySorting(std::vector<T> &data) {
    srand(time(NULL));
    std::vector<T> priorities (data.size());
    for (int i = 0; i < data.size(); ++i)
        priorities[i] = rand();
    // sort data, using the priorities as keys
}

template<class T>
void permuteByPriorityQueue(std::vector<T> &data) {
    srand(time(NULL));
    std::priority_queue<std::pair<int, T>> priorities;

    for (int i = 0; i < data.size(); ++i)
        priorities.push({rand(), data[i]});

    for (int i = 0; i < data.size(); ++i) {
        data[i] = priorities.top().second;
        priorities.pop();
    }
}

template<class T>
void randomizeInPlace(std::vector<T> &data) {
    for (int i = 0; i < data.size(); ++i)
        swap(data[i], data[i + rand() % (data.size() - i)]);
}

template<class T>
void printVector(const std::vector<T> &data) {
    std::for_each(data.begin(), data.end(), [](const auto& el){
        std::cout << el << ' ';
    });
    std::cout << '\n';
}

#endif //CORMENBOOK_PERMUTATIONS_H
