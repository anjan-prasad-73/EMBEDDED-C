/*Allocate Memory for an Integer
Goal: Understand how to allocate memory for a single variable using malloc.
Activity:
Log Session a pointer to an integer.
Use malloc to allocate memory for one integer.
Assign a value to that memory.
Print the value through the pointer.
Free the allocated memory.
Include NULL check after malloc.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    p=(int *)malloc(sizeof(int));
    if(p==NULL)
    return 0;
    printf("Enter the value\n");
    scanf("%d",p);
    printf("%d\n",*p);
    free(p);
    p=NULL;


}