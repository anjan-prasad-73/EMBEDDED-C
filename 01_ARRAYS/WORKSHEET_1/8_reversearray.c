#include<stdio.h>
int main()
{
    int arr[5]={10,20,30,40,50};
    int i=0,j=4;
    while (i<j)
    {
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
        i++;
        j--;
    }
    for(int k=0;k<5;k++)
    {
        printf("%d ",arr[k]);
    }
    return 0;
}