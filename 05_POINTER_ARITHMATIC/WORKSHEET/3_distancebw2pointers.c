#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *p1 = &arr[1];  // points to element 20
    int *p2 = &arr[4];  // points to element 50

    // Pointer subtraction gives distance in terms of number of elements
    int distance = p2 - p1;  

    printf("Pointer p1 points to arr[1] = %d\n", *p1);
    printf("Pointer p2 points to arr[4] = %d\n", *p2);
    printf("Number of elements between p1 and p2: %d\n", distance);

    return 0;
}
