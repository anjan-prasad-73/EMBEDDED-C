#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    int arr[100], n, i, j;
    int minSum = INT_MAX, sum, num1, num2;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            sum = arr[i] + arr[j];
            if(abs(sum) < minSum){
                minSum = abs(sum);
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("Pair whose sum is closest to zero: %d %d\n", num1, num2);
    return 0;
}
