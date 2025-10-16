 #include<stdio.h>

 int main()
{ 
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={1,2,6,7,5};
    int unionarr[10];
    int n1=sizeof(arr1)/sizeof(arr1[0]);
     int n2=sizeof(arr1)/sizeof(arr1[0]);
     int i,j,n3=0;
    int flag=0;
    for (i = 0; i < n1; i++)
        unionarr[n3++] = arr1[i];
    for (i = 0; i < n2; i++) {
        flag = 0;
        for (j = 0; j < n3; j++) {
            if (arr2[i] == unionarr[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            unionarr[n3++] = arr2[i];
    }

    printf("Union:");
    for (i = 0; i < n3; i++)
    printf("%d ", unionarr[i]);

    return 0;
}