#include <stdio.h>

int main() {
    int arr1[5]={1, 2, 3, 4, 5};
    int arr2[3]={2,4,5};
    int n1=sizeof(arr1)/sizeof(arr1[0]), n2=sizeof(arr2)/sizeof(arr2[0]);
    int i, j, flag;
    for(i = 0; i < n2; i++){
        flag = 0;
        for(j = 0; j < n1; j++){
            if(arr2[i] == arr1[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("Array2 is not a subset of Array1\n");
            return 0;
        }
    }

    printf("Array2 is a subset of Array1\n");
    return 0;
}
