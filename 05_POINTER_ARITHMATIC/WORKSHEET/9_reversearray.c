#include <stdio.h>

// Function to reverse array using pointers
void reverseArray(int *start, int *end) {
    while (start < end) {
        // Swap the elements pointed by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;  // Move forward
        end--;    // Move backward
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, arr + n - 1);  // Pass pointer to first and last elements

    printf("Reversed array: ");
    for (int *ptr = arr; ptr < arr + n; ptr++) {
        printf("%d ", *ptr);  // Access using pointer arithmetic
    }
    printf("\n");

    return 0;
}
