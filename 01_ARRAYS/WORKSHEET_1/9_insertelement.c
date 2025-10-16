#include<stdio.h>
int main()
{
    int arr[5]={10,20,30,40};
    int size=sizeof(arr)/sizeof(arr[0]);
    //printf("%d",size);
    int pos=2;
    for (int i = size; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] =25;
    
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}