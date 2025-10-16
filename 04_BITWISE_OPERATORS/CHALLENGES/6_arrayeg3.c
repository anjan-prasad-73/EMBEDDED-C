#include <stdio.h>

void findTwoUnique(int arr[], int n, int *num1, int *num2) {
    int xor_all = 0;

    // Step 1: XOR all numbers
    for (int i = 0; i < n; i++) {
        xor_all ^= arr[i];
    }

    // Step 2: Find rightmost set bit
    int set_bit = xor_all & -xor_all;

    *num1 = 0;
    *num2 = 0;

    // Step 3: Divide into two groups and XOR
    for (int i = 0; i < n; i++) {
        if (arr[i] & set_bit) {
            *num1 ^= arr[i];
        } else {
            *num2 ^= arr[i];
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int num1, num2;
    findTwoUnique(arr, n, &num1, &num2);

    printf("The two unique numbers are: %d and %d\n", num1, num2);

    return 0;
}
