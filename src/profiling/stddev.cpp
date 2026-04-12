#include <iostream>
#include "../math_lib/math_lib.h"

int main() {
    double x;
    double N = 0;
    double sum = 0;
    double std_sum = 0;

    while (std::cin >> x) {
        N++;

        sum = add(sum, x);
        std_sum = add(std_sum, power(x, 2));
    }

    double avg = divide(sum, N);

    double std_dev = root(2, divide(subtract(std_sum, multiply(N, power(avg, 2))), subtract(N, 1)));

    std::cout << std_dev << std::endl;

    return 0;
}
