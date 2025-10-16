/*Open an existing file and display its contents on the screen.
Input: File name: test.txt
Output: Hello, this is my first file!*/

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

    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}