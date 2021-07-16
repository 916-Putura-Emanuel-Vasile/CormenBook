//
// Created by Emanuel on 14.07.2021.
//

#ifndef CORMENBOOK_POLYNOMIAL_EVAL_HORNER_RULE_H
#define CORMENBOOK_POLYNOMIAL_EVAL_HORNER_RULE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

void testPolynomialHornerEvaluation();

template <class C>
class Polynomial {
private:
    std::vector<C> coefficients;
    int degree;
public:
    Polynomial(std::initializer_list<C> coefficients);

    template <class U>
    U hornerEvaluation(const U& point) const;

    template <class U>
    friend std::ostream& operator<< (std::ostream& os, const Polynomial<U>& polynomial);
};

template<class C>
Polynomial<C>::Polynomial(std::initializer_list<C> coefficients) : coefficients(coefficients), degree(coefficients.size()) {
}

template <class C>
std::ostream &operator<<(std::ostream &os, const Polynomial<C> &polynomial) {
    int index = 0;
    std::stringstream stream;
    std::for_each(polynomial.coefficients.begin(), polynomial.coefficients.end(), [&index, &polynomial, &stream](const auto& c) {
        if (polynomial.coefficients[index] != 0) {
            if (index) {
                if (!stream.str().empty() && stream.str()[stream.str().size() - 2] != '+' && stream.str()[stream.str().size() - 2] != '-') {
                    auto sign = " + ";
//                    if (polynomial.coefficients[index] < 0) sign = " - ";
                    stream << sign;
                }
                stream << polynomial.coefficients[index] << " * x^" << index;
            }
            else
                stream << polynomial.coefficients[index];
        }
        index++;
    });
    os << stream.str();
    return os;
}

template<class C>
template<class U>
U Polynomial<C>::hornerEvaluation(const U &point) const {
    U result = 0;
    for (int i = coefficients.size() - 1; i >= 0; --i) {
        result = result * point + coefficients[i];
    }
    return result;
}

#endif //CORMENBOOK_POLYNOMIAL_EVAL_HORNER_RULE_H
