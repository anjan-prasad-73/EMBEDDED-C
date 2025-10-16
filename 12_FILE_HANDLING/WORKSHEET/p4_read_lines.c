/*Read every line from a file and store those lines in an array.
Input: File name: lines.txt
Output: Line one, Line two, Line three (as array elements)*/


#include<stdio.h>


int main()
{
  char filename[100];

  printf("enter filename:");
  scanf("%s",filename);

  FILE *fp=fopen(filename,"r");
   if(fp==NULL)
   {
    printf("file not opened\n");
    return 1;
   }

   char ch;
   int c=0;
   char prev='\n';

   while((ch=fgetc(fp))!=EOF)
   {
    if(ch=='\n')
     c++;
     prev=ch;
   }

    if (prev != '\n') 
    {
        c++;
    }

   char lines[c][100];

   rewind(fp);
    
   for(int i=0;i<c;i++)
   {
    fgets(lines[i],sizeof(lines[i]),fp);
   }

   
    for(int i=0;i<c;i++)
   {
      printf("%s",lines[i]);
   }



}