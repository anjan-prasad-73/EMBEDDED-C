/*Add more lines to the end of a file without erasing its current content.
Input: File name: lines.txt
Number of new lines: 2
New lines: Line four, Line five
Output: File now contains: Line one, Line two, Line three, Line four, Line five*/


#include<stdio.h>


int main()
{
    char filename[100];
    printf("enter file name:");
    scanf("%s",filename);

    FILE *fp=fopen(filename,"a");
    if(fp==NULL)
    {
        printf("file not opened\n");
        return 1;
    }

   // char ch;
   // while((ch=fgetc(fp))!=EOF);
    //fseek(fp, 0, SEEK_END);
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