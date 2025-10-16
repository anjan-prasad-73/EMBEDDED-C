/*Allocate and Store a List of Integers
Goal: Practice allocating memory for an array of integers.
Activity:
Ask the user to enter the number of integers.
Allocate memory dynamically using malloc based on input.
Use a loop to take integer inputs into the allocated array.
Display the entered values.
Free the allocated memory.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int *p=(int *)malloc(n*sizeof(int));
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    for(i=0;i<n;i++)
    printf("%d ",p[i]);
    free(p);
    p=NULL;

}