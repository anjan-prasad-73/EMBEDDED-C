/*Exercise 10: Log Session and Reverse an Array
Goal: Use pointers to reverse dynamically allocated memory.

Activity:

Allocate an array of integers using malloc.
Accept n values.
Reverse the array using pointer arithmetic (not indexing).
Print reversed values.
Free the memory.*/


#include <stdio.h>
#include <stdlib.h>

void reverse_array(int *arr, int n) 
{
    int *start = arr;
    int *end = arr + n - 1;
    int temp;
    while (start < end) 
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() 
{
    int n, *arr;
    printf("Enter the no of ele: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
      return 1;

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", arr + i);
    }
    reverse_array(arr, n);

    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    free(arr);

}
