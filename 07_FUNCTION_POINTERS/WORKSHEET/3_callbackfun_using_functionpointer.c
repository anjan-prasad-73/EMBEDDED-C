#include <stdio.h>

// Callback function 1: Increment each element by 1
void increment(int *x) {
    (*x)++;
}

// Callback function 2: Double each element
void doubleValue(int *x) {
    (*x) *= 2;
}

// processArray: Accepts an array, its size, and a callback function
void processArray(int *arr, int size, void (*callback)(int*)) {
    for(int i = 0; i < size; i++) {
        callback(&arr[i]);
    }
}

// Function to print an array
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    printf("Original array: ");
    printArray(arr, 5);

    // Use increment callback
    processArray(arr, 5, increment);
    printf("After incrementing: ");
    printArray(arr, 5);

    // Use doubleValue callback
    processArray(arr, 5, doubleValue);
    printf("After doubling: ");
    printArray(arr, 5);

    return 0;
}
