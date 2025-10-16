#include <stdio.h>

int findUnique(int arr[], int n) {
    int result = 0;

    // Iterate over all 32 bits
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] & (1 << i)) {
                sum++;
            }
        }
        // If sum % 3 is 1, that bit belongs to the unique element
        if (sum % 3 != 0) {
            result |= (1 << i);
        }
    }

    return result;
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

    int unique = findUnique(arr, n);
    printf("The unique element is: %d\n", unique);

    return 0;
}
