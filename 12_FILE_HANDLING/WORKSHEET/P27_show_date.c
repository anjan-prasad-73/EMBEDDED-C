/*
Show the last modification date and time of a file.
Input: File name: a.txt
Output: Last modified: Sat Nov 26 17:32:15 2022
*/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() 
{
    struct stat fileStat;

    if (stat("a.txt", &fileStat) == 0) 
    {
        printf("Last modified: %s", ctime(&fileStat.st_mtime));
    } 
    else 
    {
        perror("stat");
    }

    return 0;
}
