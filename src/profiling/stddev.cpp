/**
 * @file stddev.cpp
 * @author Ondřej Glet (xgleton00)
 * @note Project: Calculator - JuHaBeGl
 */

#include <iostream>

#include "../math_lib/math_lib.h"

/*
 * Reads a sequence of numbers from standard input and calculates their sample standard deviation.
 */
int main() {
    double x;
    double N = 0;
    double sum = 0;
    double std_sum = 0;

    /* Process all numbers from stdin until EOF */
    while (std::cin >> x) {
        N++;

        /* Calculate the sum and the sum of squares */
        sum = add(sum, x);
        std_sum = add(std_sum, power(x, 2));
    }

    /* Calculate the arithmetic mean */
    double avg = divide(sum, N);

    /* Calculate sample standard deviation using the computational formula:
     * sqrt( (sum(x^2) - N * avg^2) / (N - 1) )
     */
    double std_dev = root(2, divide(subtract(std_sum, multiply(N, power(avg, 2))), subtract(N, 1)));

    std::cout << std_dev << std::endl;

    return 0;
}
