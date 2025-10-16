#include <stdio.h>

int main() {
     int arr[5]={8,2,7,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);  
    int maxRight = arr[n-1];
    printf("Leader elements: %d ", maxRight);

    for(int i = n-2; i >= 0; i--){
        if(arr[i] > maxRight){
            maxRight = arr[i];
            printf("%d ", maxRight);
        }
    }
    printf("\n");
    return 0;
}
