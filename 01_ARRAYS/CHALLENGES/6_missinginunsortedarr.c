#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int firstMissingPositive(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        while(arr[i] > 0 && arr[i] <= n && arr[arr[i]-1] != arr[i]){
            swap(&arr[i], &arr[arr[i]-1]);
        }
    }

    for(i = 0; i < n; i++){
        if(arr[i] != i+1)
            return i+1;
    }

    return n+1;
}

int main() {
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int missing = firstMissingPositive(arr, n);
    printf("First missing positive integer is: %d\n", missing);
    return 0;
}
