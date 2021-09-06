//
// Created by Emanuel on 03.09.2021.
//

#include "Interval.h"

Interval::Interval(int low, int high) : low(low), high(high) {
}

bool operator<(const Interval &i1, const Interval &i2) {
    return i1.low < i2.low || (i1.low == i2.low && i1.high < i2.high);
}

std::ostream &operator<<(std::ostream &os, const Interval &i) {
    os << '[' << i.low << ", " << i.high << ']';
    return os;
}

bool operator==(const Interval &i1, const Interval &i2) {
    return i1.low == i2.low && i1.high == i2.high;
}

bool operator!=(const Interval &i1, const Interval &i2) {
    return i1.low != i2.low || i1.high != i2.high;
}
