/*Reallocate an Array Dynamically
Goal: Use realloc to extend an array as needed.
Activity:
Allocate memory for 2 integers.
Ask the user for values.
Then resize the array to 5 integers using realloc.
Accept more values into the resized array.
Print all values.
Free the memory at the end.*/
#include<stdio.h>
#include<stdlib.h>
void print(int * a,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}
void input(int *a,int n)
{
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
}
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int *p=(int *)malloc(n*sizeof(int));
    int i;
    input(p,n);
    print(p,n);
    int m;
    printf("\nEnter the number of elements for reallocation\n");
    scanf("%d",&m);
    int * q=(int *)realloc(p,m*sizeof(int));
    input(q,m);
    print(q,m);
    print(p,n);
    
    free(p);
    p=NULL;

}