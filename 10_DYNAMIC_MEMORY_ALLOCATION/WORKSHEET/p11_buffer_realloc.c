/*Exercise 11: Accept Characters Until Enter Pressed
Goal: Dynamically grow a string buffer with realloc.

Activity:
 
Start with a small buffer.
Accept characters one by one.
Reallocate buffer each time a new character is added.
Stop on newline character.
Null-terminate and print the string.
Free the memory.*/


#include<stdio.h>
#include<stdlib.h>

char* read_input()
{
    char *buffer=NULL;
    int size=1,index=0;
    char ch;

    buffer=(char *)malloc(size*sizeof(char));
    if(buffer==NULL)
      return NULL;

    while(1)
    {
      ch=getchar();
      if(ch=='\n') 
        break;

       char *temp=realloc(buffer,(size+1)*sizeof(char));
       if(temp==NULL)
       {
        free(buffer);
        return NULL;
       }
       buffer=temp;
       buffer[index++]=ch;
       size++;
    }

    buffer[index]='\0';
    return buffer;
}

int main()
{
printf("Enter character:\n");
char *input=read_input();

if(input==NULL)
{
printf("Input failed.\n");
return 1;
}
printf("You entered: %s\n",input);
free(input);

}
