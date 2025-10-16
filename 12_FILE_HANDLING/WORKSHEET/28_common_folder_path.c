/*Find the common folder path among a group of file paths.
Input: /home/user/docs/a.txt, /home/user/docs/b.txt, /home/user/docs/old/c.txt
Output: /home/user/docs*/


#include <stdio.h>
#include <string.h>

#define MAX_PATHS 10
#define MAX_LEN 256

void common_prefix(char *res, const char *str) 
{
    int i = 0;
    while (res[i] && str[i] && res[i] == str[i])
        i++;
    res[i] = '\0';
}

void strip_to_folder(char *path) 
{
    int len = strlen(path);
    for (int i = len - 1; i >= 0; i--) 
    {
        if (path[i] == '/') 
        {
            path[i] = '\0';
            break;
        }
    }
}

int main() 
{
    char input[1024], paths[MAX_PATHS][MAX_LEN];
    int count = 0;

    printf("input: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    char *token = strtok(input, ",");
    while (token && count < MAX_PATHS) 
    {
        while (*token == ' ')
            token++;
        strncpy(paths[count], token, MAX_LEN);
        paths[count][MAX_LEN - 1] = 0;
        count++;
        token = strtok(NULL, ",");
    }
    if (count == 0) 
    {
        printf("No paths provided.\n");
        return 1;
    }
    char common[MAX_LEN];
    strcpy(common, paths[0]);
    for (int i = 1; i < count; i++) 
    {
        common_prefix(common, paths[i]);
        if (strlen(common) == 0)
            break;
    }
    strip_to_folder(common);
    printf("output: %s\n", common);
    return 0;
}
