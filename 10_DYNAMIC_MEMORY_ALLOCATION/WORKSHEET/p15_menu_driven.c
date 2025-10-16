/*Exercise 15: Dynamic Menu-Driven Array
Goal: Handle operations on a dynamic array with growing size.

Activity: 
Start with an empty array.
Provide a menu with options: Add element, Display, Exit.
Use realloc each time user adds an element.
Print array contents.
Free memory on exit.*/


#include <stdio.h>
#include <stdlib.h>

void addElement(int **arr,int *size)
{
    int element;
    printf("Enter element to add:");
    scanf("%d",&element);
    int *temp=realloc(*arr,(*size+1)*sizeof(int));
    if(temp==NULL)
    {
        printf("Memory allocation failed.\n");
        free(*arr);
        exit(1);
    }
    *arr=temp;
    (*arr)[*size]=element;
    (*size)++;
}

void displayArray(int *arr,int size)
{
    if(size==0)
    {
        printf("Array is empty.\n");
    }
    else
    {
        printf("Array:");
        for(int i=0;i<size;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

int main(){
    int *arr=NULL,size=0,choice;
    while(1)
    {
        printf("\nMenu:\n1.Add element\n2.Display\n3.Exit\nChoose an option:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:addElement(&arr,&size);
                    break;
            case 2:displayArray(arr,size);
                    break;
            case 3:free(arr); 
                    return 0;
            default:printf("Invalid option. Try again.\n");
        }
    }
}
