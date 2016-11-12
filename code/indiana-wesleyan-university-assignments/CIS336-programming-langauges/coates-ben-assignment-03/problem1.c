// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Assingment 3, Problem 1
// =========================================

#include <stdio.h>

int fun (int*k) {
    *k += 4;
    return 3 * (*k) - 1;
}

int main () {
    int i = 10, j = 10, sum1, sum2;
    sum1 = (i/2) + fun(&i);
    sum2 = fun(&j) + (j/2);
    
    printf("%d\n", sum1);
    printf("%d\n", sum2);
    
    return 0;
}