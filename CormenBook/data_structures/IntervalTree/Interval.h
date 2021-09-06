//
// Created by Emanuel on 03.09.2021.
//

#ifndef CORMENBOOK_INTERVAL_H
#define CORMENBOOK_INTERVAL_H

#include <iostream>

class Interval {
private:
    int low, high;
public:
    Interval() = default;
    Interval(int low, int high);

    friend bool operator== (const Interval& i1, const Interval& i2);
    friend bool operator!= (const Interval& i1, const Interval& i2);
    friend bool operator< (const Interval& i1, const Interval& i2);
    friend std::ostream& operator<< (std::ostream& os, const Interval& i);
    friend bool intervalsOverlap(const Interval& i1, const Interval& i2);

    inline int getLow() const { return low; }
    inline int getHigh() const { return high; }
private:
    friend class IntervalTree;
};


#endif //CORMENBOOK_INTERVAL_H
