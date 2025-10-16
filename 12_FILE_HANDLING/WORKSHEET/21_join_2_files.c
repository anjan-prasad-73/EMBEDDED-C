/*Join two files together and save the result in a new file.
Input: File 1: a.txt (AAA)
File 2: b.txt (BBB)
New file: ab.txt
Output: ab.txt content: AAA
BBB*/

#include <stdio.h>

void join_files(const char *file1, const char *file2, const char *newfile) {
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    FILE *fp3 = fopen(newfile, "w");
    char ch;

    if (!fp1 || !fp2 || !fp3) 
    {
        printf("file not opened\n");
        return;
    }

    while ((ch = fgetc(fp1)) != EOF)
        fputc(ch, fp3);

    fputc('\n', fp3);

    while ((ch = fgetc(fp2)) != EOF)
        fputc(ch, fp3);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

int main() {
    char file1[100], file2[100], newfile[100], ch;
    FILE *fp3;

    printf("Enter first file name: ");
    scanf("%s", file1);

    printf("Enter second file name: ");
    scanf("%s", file2);

    printf("Enter new file name: ");
    scanf("%s", newfile);

    join_files(file1, file2, newfile);

    fp3 = fopen(newfile, "r");
    if (!fp3) 
    {
        printf("file not opened\n");
        return 1;
    }

    printf("output:\n");
    while ((ch = fgetc(fp3)) != EOF)
        putchar(ch);

    fclose(fp3);
    return 0;
}
