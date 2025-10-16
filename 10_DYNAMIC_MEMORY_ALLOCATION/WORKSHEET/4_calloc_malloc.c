/* Compare malloc and calloc
Goal: Learn the key difference between malloc and calloc.
Activity:
Allocate two arrays using malloc and calloc with the same size.
Print the default values in both arrays.
Use a loop for printing to understand initialization differences.
Free both arrays.*/
#include<stdio.h>
#include<stdlib.h>
void print(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int *p=(int *)calloc(n,sizeof(int));
    int *q=(int *)malloc(n*sizeof(int));
    int i;
    printf("Default values of calloc\n");
    print(p,n);
    printf("\nDefault values of malloc\n");
    print(q,n);
    printf("\nenter the array elements memory allocated to it though calloc\n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    print(p,n);
    printf("\nenter the array elements memory allocated to it though malloc\n");
    for(i=0;i<n;i++)
    scanf("%d",&q[i]);
    print(q,n);

}