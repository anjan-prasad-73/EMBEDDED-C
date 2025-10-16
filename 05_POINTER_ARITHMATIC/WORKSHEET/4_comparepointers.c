#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *p1 = &arr[2];  // points to element 30
    int *p2 = &arr[4];  // points to element 50

    // Compare pointers
    if (p1 < p2) {
        printf("p1 points to the element with a smaller index: %d\n", *p1);
    } else if (p2 < p1) {
        printf("p2 points to the element with a smaller index: %d\n", *p2);
    } else {
        printf("Both pointers point to the same element: %d\n", *p1);
    }

    return 0;
}
