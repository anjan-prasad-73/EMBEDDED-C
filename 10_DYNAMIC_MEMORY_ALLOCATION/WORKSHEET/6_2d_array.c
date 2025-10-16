/*Log Session a Dynamic 2D Array
Goal: Learn how to allocate and access a 2D array dynamically.
Activity:
Ask the user for number of rows and columns.
Allocate memory for an array of row pointers.
Allocate each row separately using malloc.
Accept values for each row-column index.
Display the matrix.
Free each row and then the row pointer array.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n;
    printf("enter the size of matrix \n");
    scanf("%d%d",&m,&n);
    int **p=(int **)malloc(m*sizeof(int *));
    int i,j;
    for(i=0;i<m;i++)
    p[i]=(int *)malloc(n*sizeof(int));
    printf("Enter the array elements\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&p[i][j]);
    }
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%2d ",p[i][j]);
        printf("\n");
    }
    for(i=0;i<m;i++)
    free(p[i]);
    free(p);

}