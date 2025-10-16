/*25.List all the files found inside a directory (folder).
Input: Directory: myfolder/
Output: file1.txt, file2.txt, notes.doc*/
#include <stdio.h>
#include <dirent.h>

int main() 
{
    char directory[100];
    struct dirent *entry;
    DIR *dp;

    printf("Enter directory name: ");
    scanf("%s", directory);

    dp = opendir(directory);
    if (dp == NULL) 
    {
        printf("Error opening directory.\n");
        return 1;
    }

    printf("Files in directory %s:\n", directory);
    while ((entry = readdir(dp)) != NULL)
    { 
        if (entry->d_name[0] != '.') 
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dp);
    return 0;
}
