/*18.Display the lines of a file in reverse order (from last to first).
Input: File name: lines.txt
Output: Shows lines from bottom to top*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 1024

int main() 
{
    char filename[100];
    char *lines[MAX_LINES];
    char buffer[MAX_LENGTH];
    int count = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) 
    {
        printf("Could not open file.\n");
        return 1;
    }

    while (fgets(buffer, MAX_LENGTH, fp)) 
    {
        lines[count] = malloc(strlen(buffer) + 1);
        strcpy(lines[count], buffer);
        count++;
        if (count >= MAX_LINES) break;
    }
    fclose(fp);

    printf("Content in reverse order:\n");
    for (int i = count - 1; i >= 0; i--) 
    {
        printf("%s", lines[i]);
        free(lines[i]);
        if(i==count-1)
        printf("\n");
    }

    return 0;
}
