#include<stdio.h>

int main()
{
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int r=2;
    int first,j,i;
    for(i=0;i<r;i++)
    {   first=arr[0];
        for( j=0;j<n-1;j++)
        {
            arr[j]=arr[j+1];
        }
        arr[j]=first;
    }


    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}