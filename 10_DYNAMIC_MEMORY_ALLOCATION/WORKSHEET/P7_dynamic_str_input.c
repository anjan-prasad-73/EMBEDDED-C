// Handle strings with dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[20];
    printf("Enter the string:\n");
    scanf("%[^\n]",s);

    char* p=malloc(sizeof(strlen(s)+1));
    strcpy(p,s);
    printf("%s\n",p);
    free(p);
}