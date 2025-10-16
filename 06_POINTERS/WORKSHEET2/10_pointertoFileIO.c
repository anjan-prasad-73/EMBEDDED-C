#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (!fp) return 1;

    // Determine file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    // Allocate buffer
    char *buffer = (char *)malloc(size + 1);
    if (!buffer) return 1;

    fread(buffer, 1, size, fp);
    buffer[size] = '\0'; // Null-terminate

    printf("File content:\n%s\n", buffer);

    free(buffer);
    fclose(fp);

    return 0;
}
