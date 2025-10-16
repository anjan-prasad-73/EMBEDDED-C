/*
Count how many lines in a file end with a semicolon.
Input: File: data.txt (lines, some end with ;)
Output: Lines ending with semicolon: 2
*/

#include <stdio.h>
#include <string.h>

int main() 
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    char line[1000];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            len--;
        }
        if (len > 0 && line[len - 1] == ';') {
            count++;
        }
    }

    fclose(file);
    printf("Lines ending with semicolon: %d\n", count);
    return 0;
}
