//
// Created by Emanuel on 02.08.2021.
//

#ifndef CORMENBOOK_RADIX_SORT_H
#define CORMENBOOK_RADIX_SORT_H

#include <vector>

void modifiedCountingSort(std::vector<int>& data, int digit_modulo_order, int max_no = 9);
void radixSort(std::vector<int>& data, int digits_no);
void testRadixSort();

#endif //CORMENBOOK_RADIX_SORT_H
