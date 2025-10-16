/*Exercise 19: Dynamic Array of Pointers to Integers
Goal: Work with array of pointers using malloc.

Activity:

Ask user for count.
Allocate array of int* pointers.
Use malloc to assign an integer for each pointer.
Assign and print values.
Free all integers and the array.*/



#include <stdio.h>
#include <stdlib.h>

int **allocateArray(int count)
{
    int **arr=malloc(count*sizeof(int*));
    if(arr==NULL)return NULL;

    for(int i=0;i<count;i++)
    {
        arr[i]=malloc(sizeof(int));
        if(arr[i]==NULL)
        {
            for(int j=0;j<i;j++)free(arr[j]);
            free(arr);
            return NULL;
        }
        *arr[i]=i*10;
    }
    return arr;
}

void printArray(int **arr,int count)
{
    printf("Values:\n");
    for(int i=0;i<count;i++)printf("%d ",*arr[i]);
    printf("\n");
}

void freeArray(int **arr,int count)
{
    for(int i=0;i<count;i++)free(arr[i]);
    free(arr);
}

int main()
{
    int count;
    printf("Enter count:");
    scanf("%d",&count);
    int **arr=allocateArray(count);
    if(arr==NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printArray(arr,count);
    freeArray(arr,count);
    return 0;
}
