/*Count both the number of words and the number of characters in a file.
Input: File name: info.txt (content: This is a test file.)
Output: Words: 5
Characters: 21*/


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
    int char_count=0,word=0,flag=0;


    while((ch=fgetc(fp))!=EOF)
    {
        char_count++;

        if(ch==' '||ch=='\n'||ch=='\t')
        {
            flag=0;
        }
        else if (flag==0)
        {
            word++;
            flag=1;
        }
        

    }

    fclose(fp);

    printf("char count=%d word count=%d\n",char_count,word);


}