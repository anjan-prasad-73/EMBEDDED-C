/*Zero-Initialize an Integer Array
Goal: Understand how calloc initializes memory.
Activity:
Ask the user for the number of elements.
Allocate memory using calloc.
Print the initial values (before user input).
Assign values, then display them.
Free the memory after use.*/
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
    int i;
    print(p,n);
    printf("\nenter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    print(p,n);
}