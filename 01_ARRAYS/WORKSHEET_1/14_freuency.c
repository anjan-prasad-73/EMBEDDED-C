#include<stdio.h>
int main()
{  
    int arr[5]={1,1,3,2,3};
    int flag,i,j,count;
    int n=sizeof(arr)/sizeof(arr[0]);

    for (i = 0; i < n; i++) {
        flag = 0;

        
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            count = 1;
            for (j = i + 1; j < n; j++) {
                if (arr[i] == arr[j])
                    count++;
            }
            printf("%d  %d \n", arr[i], count);
        }
    }
    return 0;
}