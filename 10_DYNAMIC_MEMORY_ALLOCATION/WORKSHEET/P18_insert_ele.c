/* Insert Element at Any Position
Goal: Modify dynamic array and shift elements.
Activity:
Allocate memory for an array.
Accept n values.
Ask user to insert a value at a specific position.
Use realloc to increase size.
Shift elements and insert new value.
Print final array and free memory.*/

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    return 0;
    int i,j;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int c,x;
    printf("Enter element and index position for inserting\n");
    scanf("%d%d",&c,&x);
    int *q=(int *)realloc(a,sizeof(int));
    if(q==NULL)
        return 0;
    
    for(i=n-1;i>=x;i--)
    {
        q[i+1]=q[i];
    }
    q[x]=c;
    for(i=0;i<n+1;i++)
        printf("%d ",q[i]);

}