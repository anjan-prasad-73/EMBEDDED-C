/*Make a new file and save some text entered by the user.
Input: File name: test.txt
Text: Hello, this is my first file!
Output: File 'test.txt' created and saved.*/



#include<stdio.h>

int main()
{
    char filename[100];
    char text[100];

    printf("enter file name:");
    scanf("%s",filename);

    getchar();
    printf("enter text:");
    fgets(text,sizeof(text),stdin);

    FILE *fp=fopen(filename,"w");

    if(fp==NULL)
    {
        printf("file not created\n");
        return 1;
    }

    fputs(text,fp);
    fclose(fp);
    printf("File '%s' created and saved",filename);


}
