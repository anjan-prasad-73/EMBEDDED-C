/*20.Decrypt a scrambled (encrypted) file and make it readable again.
Input: File name: secret.txt (content: encrypted)
Output: File now contains: my password*/
#include <stdio.h>

int main() 
{
    char filename[100];
    char ch;
    int key;
    printf("enter the key for decryption\n");
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
    printf("File decrypted successfully.\n");
    return 0;
}
