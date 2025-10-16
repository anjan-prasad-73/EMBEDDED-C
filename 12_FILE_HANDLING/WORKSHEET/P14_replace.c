/*
Replace every use of a chosen word in a file with a different word.
Input: File name: info.txt
Word to replace: file
Replacement: document
Output: Content after: This is a test document.
*/

#include <stdio.h>
#include <string.h>

#define MAX 10000

int main(int argc,char** argv) 
{
    FILE *fp = fopen(argv[1], "r");
    char buffer[MAX], *pos;
    char a[20],b[20];

    printf("Enter the word to replace:\n");
    scanf(" %s",a);
    printf("Enter the replacement:\n");
    scanf(" %s",b);

    char temp[MAX];
    
    fread(buffer, 1, MAX, fp);
    fclose(fp);

    while ((pos = strstr(buffer, a)) != NULL) 
    {
        int len = pos - buffer;
        temp[0] = '\0';
        strncat(temp, buffer, len);
        strcat(temp,b);
        strcat(temp, pos + strlen(a));
        strcpy(buffer, temp);
    }

    fp = fopen(argv[1], "w");
    fputs(buffer, fp);
    fclose(fp);

    printf("Replacement done. File overwritten.\n");
    return 0;
}
