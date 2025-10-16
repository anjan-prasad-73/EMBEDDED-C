#include <stdio.h>

int main() {
    int arr[100], n, i;
    long long totalSum = 0, totalSqSum = 0;
    int sumArr = 0, sqSumArr = 0;
    double a, b;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sumArr += arr[i];
        sqSumArr += arr[i]*arr[i];
    }

    int N = n + 2; // numbers from 1 to n+2
    totalSum = (N*(N+1))/2;
    totalSqSum = (N*(N+1)*(2*N+1))/6;

    double S = totalSum - sumArr; // a + b
    double P = totalSqSum - sqSumArr; // a^2 + b^2

    double D = sqrt(2*P - S*S); // sqrt((a-b)^2)

    a = (S + D)/2;
    b = (S - D)/2;

    printf("Missing numbers: %.0lf %.0lf\n", a, b);
    return 0;
}
