#include "algorithms/polynomial_eval_horner_rule.h"
#include "algorithms/maximum_subarray_problem.h"
#include "exercises/exercise2-4-d.h"

void test();

int main() {
    test();
    return 0;
}

void test() {
    testPolynomialHornerEvaluation();
    testCountInversions();
    testFindMaximumSubarray();
}
