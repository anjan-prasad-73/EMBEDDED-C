#include <stdio.h>

// Bubble Sort
void bubbleSort(int *arr, int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int *arr, int n) {
    for(int i=0; i<n-1; i++) {
        int min_idx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Insertion Sort
void insertionSort(int *arr, int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Function to print an array
void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    // Array of function pointers
    void (*sortFuncs[])(int*, int) = {bubbleSort, selectionSort, insertionSort};

    printf("Choose sorting method:\n");
    printf("0: Bubble Sort\n1: Selection Sort\n2: Insertion Sort\n");
    int choice;
    scanf("%d", &choice);

    if(choice < 0 || choice > 2) {
        printf("Invalid choice!\n");
        return 1;
    }

    // Call the selected sorting function via pointer
    sortFuncs[choice](arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
