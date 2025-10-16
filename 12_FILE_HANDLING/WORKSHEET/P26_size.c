/*26.Find out how big a file is (in bytes).
Input: File name: a.txt
Output: Size: 36 bytes*/
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];
    long size;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);

    printf("Size: %ld bytes\n", size);

    return 0;
}
