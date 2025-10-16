/*Change all the letters in a file to uppercase.
Input: File name: info.txt (content: Hello World!)
Output: HELLO WORLD!*/


#include<stdio.h>

void uppercase(char filename[])
{
    FILE *fp1=fopen(filename,"r");
    FILE *fp2=fopen("temp.txt","w");

    char ch;

    while((ch=fgetc(fp1))!=EOF)
    {
        if(ch>='a' && ch<='z')
        {
            ch=ch-32;
            fputc(ch,fp2);
            continue;
        }
         fputc(ch,fp2);
    }
    fclose(fp1);
    fclose(fp2);

    remove(filename);

    rename("temp.txt",filename);

}

int main()
{
    char filename[50];
    printf("enter file name:");
    scanf("%s",filename);

     uppercase(filename);

     FILE *fp=fopen(filename,"r");

    if(fp==NULL)
    {
        printf("file not opened\n");
        return 1;
    }
    char ch;
    printf("output:\n");
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}

