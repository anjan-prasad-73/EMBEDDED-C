/*Count how many lines are present in a text file.
Input: File name: lines.txt
Output: Total lines: 5*/

#include<stdio.h>

int main()
{
    char filename[100];
    

    printf("enter file name:");
    scanf("%s",filename);

    FILE *fp=fopen(filename,"r");

    if(fp==NULL)
    {
        printf("file not opened\n");
        return 1;
    }

    char ch;
    int c=0;
    int flag;
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
        {
            c++;
            flag=1;
        }
        else
        {
            flag=0;
        }
    }

    if(flag==0)
    c++;


    printf("total lines: %d\n",c);
}