#include <stdio.h>
#include <stdlib.h>

int maxLenEqual01(int arr[], int n) {
    int *map = (int*)malloc(sizeof(int) * (2*n + 1));
    for(int i = 0; i < 2*n+1; i++) map[i] = -2; // initialize
    int sum = 0, maxLen = 0;

    map[n] = -1; // sum=0 mapped to index -1 (offset by n)

    for(int i = 0; i < n; i++){
        int val = (arr[i] == 0) ? -1 : 1;
        sum += val;
        int index = sum + n;

        if(map[index] != -2){
            int len = i - map[index];
            if(len > maxLen) maxLen = len;
        } else {
            map[index] = i;
        }
    }

    free(map);
    return maxLen;
}

int main() {
    int arr[] = {0, 1, 0, 1, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int length = maxLenEqual01(arr, n);
    printf("Length of longest subarray with equal 0s and 1s: %d\n", length);
    return 0;
}
