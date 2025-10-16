/*19.Encrypt (scramble) a file’s content so it can’t be read easily.
Input: File name: secret.txt (content: my password)
Output: File now contains: (garbled/encrypted text)*/
#include <stdio.h>

int main() 
{
    char filename[100];
    char ch;
    int key;
    printf("Enter the key for encryption\n");
    scanf("%d",&key);

    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");
    if (!fp) 
    {
        printf("Could not open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) 
    {
        fseek(fp, -1, SEEK_CUR); 
        fputc(ch ^ key, fp);     
        fflush(fp);
    }

    fclose(fp);
    printf("File encrypted successfully.\n");
    return 0;
}
