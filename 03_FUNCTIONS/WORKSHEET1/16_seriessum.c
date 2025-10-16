#include <stdio.h>

// Function to compute factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to compute series sum
int seriesSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += factorial(i) / i;
    }
    return sum;
}

int main() {
    int n = 5;
    int sum = seriesSum(n);
    printf("The sum of the series is: %d\n", sum);
    return 0;
}
