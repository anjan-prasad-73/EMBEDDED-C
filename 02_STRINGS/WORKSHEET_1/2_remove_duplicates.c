#include <stdio.h>

int main() {
    char str[] = "programming";
    int i, j, k;
    char result[100];
    k = 0;

    for(i = 0; str[i] != '\0'; i++){
        int found = 0;
        for(j = 0; j < k; j++){
            if(str[i] == result[j]){
                found = 1;
                break;
            }
        }
        if(!found) result[k++] = str[i];
    }
    result[k] = '\0';

    for(i = 0; i < k; i++) printf("%c", result[i]);
}
