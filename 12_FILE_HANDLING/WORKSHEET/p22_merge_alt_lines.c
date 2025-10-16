/*Merge alternate lines from two files into a third file.
Input: File 1: a.txt (A1, A2)
File 2: b.txt (B1, B2)
New file: merge.txt
Output: merge.txt: A1, B1, A2, B2*/


#include <stdio.h>
#include <string.h>

void merge_alternate_lines(const char *file1, const char *file2, const char *outfile) 
{
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    FILE *fp3 = fopen(outfile, "w");
    char line1[256], line2[256];
    int read1, read2;
    

    if (!fp1 || !fp2 || !fp3) 
    {
        printf("file not opened\n");
        return;
    }

    while (1) 
    {
        read1 = fgets(line1, sizeof(line1), fp1) != NULL;
        read2 = fgets(line2, sizeof(line2), fp2) != NULL;
        if (!read1 && !read2) 
           break;
        if (read1) 
        {
            line1[strcspn(line1, "\n")] = 0;
            fprintf(fp3, "%s", line1);
        }
        if (read2) 
        {
            line2[strcspn(line2, "\n")] = 0;
            fprintf(fp3, ", %s", line2);
        }
        fprintf(fp3, "\n");
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

int main() 
{
    char file1[100], file2[100], outfile[100], ch;
    FILE *fp;

    printf("Enter first file name: ");
    scanf("%s", file1);
    printf("Enter second file name: ");
    scanf("%s", file2);
    printf("Enter output file name: ");
    scanf("%s", outfile);

    merge_alternate_lines(file1, file2, outfile);

    fp = fopen(outfile, "r");
    if (!fp) 
    {
        printf("file not opened\n");
        return 1;
    }

    printf("output:\n", outfile);
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
    return 0;
}
