/*8.Read a value from a file into a variable, and also write a variable’s value back into a file.
Input: File name: number.txt (contains: 42)
Output: Read variable: 42; After writing value 100, file now contains: 100*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f1=malloc(100*sizeof(char));
    if(f1==NULL) return 0;
    printf("Enter the filename\n");
    scanf(" %s",f1);
    FILE *fp=fopen(f1,"r");
    if(fp==NULL) 
    {
        perror("fopen");
        return 0;
    }
    int n;
    fscanf(fp,"%d",&n);
    printf("the data read from \"%s\" is %d\n",f1,n);
    fp=fopen(f1,"w");
    fprintf(fp,"%d",100);
    printf("After writing value 100\nfile now contains 100\n");
}