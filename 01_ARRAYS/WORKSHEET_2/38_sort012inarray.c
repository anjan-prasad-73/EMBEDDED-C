#include <stdio.h>
//Dutch nationl flg algorithm
int main() {
    int arr[8]={0 ,1 ,2 ,0, 1 ,2 ,1 ,0};
    int i,low = 0, mid = 0, high;
   int n=sizeof(arr)/sizeof(arr[0]);
    high = n - 1;

    while(mid <= high){
        if(arr[mid] == 0){
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++; mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}
