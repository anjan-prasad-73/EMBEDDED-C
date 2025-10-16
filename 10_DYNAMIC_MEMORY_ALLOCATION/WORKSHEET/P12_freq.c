/*Track Frequency of Elements
Goal: Use calloc for zero-initialized counting.
Activity:
Allocate an integer array of size 100 using calloc.
Accept n numbers between 0 and 99.
Increment the value at each index to count frequency.
Display the frequencies.
Free the memory.*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    
    int *p=(int *)calloc(100,sizeof(int));
    if(p==NULL)
    return 0;
    int i,n;
    printf("Enter how many numbers you want to input\n");
    scanf("%d",&n);
    printf("\nenter the number in range between 0 to 99\n");
    int num;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        if (num >= 0 && num < 100) 
        {
            p[num]++;
        } else 
        {
            printf("Number %d is out of range. Skipped.\n", num);
        }
    }
        printf("Frequencies:\n");
    for (int i = 0; i < 100; i++) 
    {
        if (p[i] > 0) 
        {
            printf("Number %d: %d times\n", i, p[i]);
        }
    }

    free(p);

}