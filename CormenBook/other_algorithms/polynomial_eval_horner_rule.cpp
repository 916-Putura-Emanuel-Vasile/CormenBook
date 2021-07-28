//
// Created by Emanuel on 14.07.2021.
//

#include <iostream>
#include <cassert>

#include "polynomial_eval_horner_rule.h"

void testPolynomialHornerEvaluation() {
    std::cout << "...testing Horner evaluation for polynomials\n";

    Polynomial<int> p1 {10, 20, 30};
    assert(p1.hornerEvaluation(1.5) == 107.5);
    assert(p1.hornerEvaluation(1) == 60);

    std::stringstream stream;
    stream << p1;
    assert(stream.str() == "10 + 20 * x^1 + 30 * x^2");

    Polynomial<int> p2 {10, -20, 30};
    assert(p2.hornerEvaluation(1) == 20);

    Polynomial<double> p3 {0, -2, 0, 7.9};
    assert(p3.hornerEvaluation<double>(1.1));
}
