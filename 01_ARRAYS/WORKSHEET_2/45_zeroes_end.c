#include <stdio.h>

int main() {
    int arr[100], n, i, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(i = 0; i < n; i++){
        if(arr[i] != 0) arr[count++] = arr[i];
    }

    while(count < n) arr[count++] = 0;

    printf("Output: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}
