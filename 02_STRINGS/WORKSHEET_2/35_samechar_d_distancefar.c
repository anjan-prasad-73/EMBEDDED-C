#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256

typedef struct {
    char ch;
    int freq;
} CharFreq;

// Comparator for sorting frequencies (descending)
int cmp(const void *a, const void *b) {
    return ((CharFreq*)b)->freq - ((CharFreq*)a)->freq;
}

int rearrangeString(char* str, int d, char* result) {
    int len = strlen(str);
    if (d <= 1) { 
        strcpy(result, str); 
        return 1; 
    }

    int freq[MAX_CHAR] = {0};
    for (int i = 0; i < len; i++) freq[str[i]]++;

    CharFreq arr[MAX_CHAR];
    int n = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            arr[n].ch = (char)i;
            arr[n].freq = freq[i];
            n++;
        }
    }

    // Result string placeholder
    char res[len+1];
    int pos = 0;

    while (pos < len) {
        qsort(arr, n, sizeof(CharFreq), cmp);

        int placed = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].freq <= 0) continue;

            // Check if we can place this character at current position
            int canPlace = 1;
            for (int j = 1; j < d && pos-j >= 0; j++) {
                if (res[pos-j] == arr[i].ch) {
                    canPlace = 0;
                    break;
                }
            }

            if (canPlace) {
                res[pos++] = arr[i].ch;
                arr[i].freq--;
                placed = 1;
                break;
            }
        }

        if (!placed) return 0;  // Not possible to place any char
    }

    res[len] = '\0';
    strcpy(result, res);
    return 1;
}

int main() {
    char str[] = "aabbcc";
    int d = 2;
    char result[100];
    if (rearrangeString(str, d, result)) {
        printf("Output: %s\n", result);  // Output: abcabc
    } else {
        printf("Not possible to rearrange.\n");
    }
    return 0;
}
