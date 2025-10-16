/*
Show all the contents in a file and also print the total number of lines.
Input: File name: lines.txt
Output: (shows all lines)
Total lines: 5
*/

#include<stdio.h>
int main()
{
    int l = 0;
    FILE* fp = fopen("test.txt","r");
    char c;
    while((c=fgetc(fp))!=EOF)
    {
        if(c == '\n')
        l++;
        printf("%c",c);
    }
    printf("\nTotal Lines: %d\n",l);
}