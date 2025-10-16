/*Capitalize the first letter of each word in a file.
Input: File name: info.txt (content: hello world!)
Output: Hello World!*/




#include <stdio.h>

void capitalize_words(char filename[]) 
{
    FILE *fp1 = fopen(filename, "r");
    FILE *fp2 = fopen("temp.txt", "w");
    char ch;
    int new_word = 1;

    if (!fp1 || !fp2) 
    {
        printf("file not opened\n");
        return;
    }

    while ((ch = fgetc(fp1)) != EOF) 
    {
        if (new_word && ch >= 'a' && ch <= 'z')
            ch = ch - 32;

        fputc(ch, fp2);

        if (ch == ' ' || ch == '\n' || ch == '\t')
            new_word = 1;
        else
            new_word = 0;
    }

    fclose(fp1);
    fclose(fp2);

    remove(filename);
    rename("temp.txt", filename);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    capitalize_words(filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) 
    {
        printf("File not found.\n");
        return 1;
    }

     char ch;

    printf("output:\n");
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);

    return 0;
}
