/*Exercise 13: Memory Leak Simulation
Goal: Understand what a memory leak is.

Activity: 
Allocate memory using malloc and assign values.
Intentionally skip free().
Run the program with tools like valgrind to observe the leak.
Fix the leak by adding proper free().
*/


#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=(int*)malloc(5*sizeof(int));
    if(ptr==NULL)
    {
      printf("Memory allocation failed.\n");
      return 1;
    }
    for(int i=0;i<5;i++)
    {
      ptr[i]=i*10;
      printf("%d ",ptr[i]);
    }
    printf("\n");
    free(ptr);

}
