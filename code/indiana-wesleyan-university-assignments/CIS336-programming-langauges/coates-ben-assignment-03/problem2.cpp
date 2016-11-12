// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Assignment 3, Problem 2
// =========================================


#include <iostream>

int fun (int*k) {
    *k += 4;
    return 3 * (*k) - 1;
}

int main () {
    int i = 10, j = 10, sum1, sum2;
    sum1 = (i/2) + fun(&i);
    sum2 = fun(&j) + (j / 2);

    std::cout << sum1 << std::endl;
    std::cout << sum2 << std::endl;

    return 0;
}