#include <stdio.h>

int main() {
    int arr[7]={-7 ,1, 5 ,2 ,-4 ,3 ,0}, n, i, totalSum = 0, leftSum = 0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(i = 0; i < n; i++){
        totalSum += arr[i];
    }

    for(i = 0; i < n; i++){
        totalSum -= arr[i];
        if(leftSum == totalSum){
            printf("Equilibrium index is %d\n", i);
            return 0;
        }
        leftSum += arr[i];
    }

    printf("No equilibrium index found.\n");
    return 0;
}
