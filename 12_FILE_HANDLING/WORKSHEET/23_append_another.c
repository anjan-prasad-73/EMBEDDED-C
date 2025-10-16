/*23.Take everything from one file and append it to the end of another file.
Input: File1: main.txt (Main)
File2: extra.txt (Extra)
Output: main.txt now contains: Main, Extra*/
#include <stdio.h>

int main() 
{
    char file1[100], file2[100];
    char ch;

    printf("Enter destination file name");
    scanf("%s", file1);
    printf("Enter source file name to append");
    scanf("%s", file2);

    FILE *fp1 = fopen(file1, "a");
    FILE *fp2 = fopen(file2, "r");

    if (!fp1 || !fp2) 
    {
        printf("Error opening files.\n");
        return 1;
    }

    while ((ch = fgetc(fp2)) != EOF) 
    {
        fputc(ch, fp1);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Content from %s appended to %s successfully.\n", file2, file1);
    return 0;
}
