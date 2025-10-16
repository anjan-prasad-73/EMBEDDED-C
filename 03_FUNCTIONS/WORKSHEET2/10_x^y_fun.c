#include <stdio.h>

// Recursive function to calculate x^y
double power(double x, int y) {
    if (y == 0) return 1;
    if (y > 0)
        return x * power(x, y - 1);
    else
        return 1 / power(x, -y); // Handle negative exponent
}

int main() {
    double x;
    int y;

    printf("Enter base (x): ");
    scanf("%lf", &x);
    printf("Enter exponent (y): ");
    scanf("%d", &y);

    double result = power(x, y);
    printf("%.2lf^%d = %.2lf\n", x, y, result);

    return 0;
}
