/*Take several lines from the user and write all of them into a file.
Input: File name: lines.txt
Number of lines: 3
Lines: Line one, Line two, Line three
Output: All lines saved in 'lines.txt'.*/


#include<stdio.h>


int main()
{
    char filename[100];
    printf("enter file name:");
    scanf("%s",filename);

    FILE *fp=fopen(filename,"w");
    if(fp==NULL)
    {
        printf("file not opened\n");
        return 1;
    }

    int n;

    printf("number of lines:");
    scanf("%d",&n);

    char lines[100];

    getchar();
    printf("lines:");
    for(int j=0;j<n;j++)
    {
        fgets(lines,sizeof(lines),stdin);
        fputs(lines,fp);

    }

    

    fclose(fp);
    printf("all lines saved in '%s'",filename);


}