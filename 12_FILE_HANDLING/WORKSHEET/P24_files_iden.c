/*24.Check if two files are exactly the same or not.
Input: File1: a.txt, File2: b.txt
Output: Files are identical or Files are different*/
#include <stdio.h>

int main() 
{
    char file1[100], file2[100];
    FILE *fp1, *fp2;
    char ch1, ch2;

    printf("Enter first file name: ");
    scanf("%s", file1);
    printf("Enter second file name: ");
    scanf("%s", file2);

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (!fp1 || !fp2) 
    {
        printf("Error opening files.\n");
        return 1;
    }

    int identical = 1;
    while ((ch1 = fgetc(fp1)) != EOF && (ch2 = fgetc(fp2)) != EOF) 
    {
        if (ch1 != ch2) {
            identical = 0;
            break;
        }
    }

    if ((ch1 != EOF && ch2 == EOF) || (ch1 == EOF && ch2 != EOF)) 
    {
        identical = 0;
    }

    if (identical)
        printf("Files are identical.\n");
    else
        printf("Files are different.\n");

    fclose(fp1);
    fclose(fp2);
    return 0;
}
