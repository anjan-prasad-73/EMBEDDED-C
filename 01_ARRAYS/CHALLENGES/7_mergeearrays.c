#include <stdio.h>
#include <math.h>

void mergeInPlace(int A[], int B[], int n, int m){
    int gap = ceil((float)(n + m) / 2);
    int i, j;

    while(gap > 0){
        // Compare in A[]
        for(i = 0; i + gap < n; i++){
            if(A[i] > A[i + gap]){
                int temp = A[i];
                A[i] = A[i + gap];
                A[i + gap] = temp;
            }
        }

        // Compare in A[] and B[]
        for(j = (gap > n) ? gap - n : 0; i < n && j < m; i++, j++){
            if(A[i] > B[j]){
                int temp = A[i];
                A[i] = B[j];
                B[j] = temp;
            }
        }

        // Compare in B[]
        if(j < m){
            for(j = 0; j + gap < m; j++){
                if(B[j] > B[j + gap]){
                    int temp = B[j];
                    B[j] = B[j + gap];
                    B[j + gap] = temp;
                }
            }
        }

        if(gap == 1) gap = 0;
        else gap = ceil((float)gap / 2);
    }
}

int main() {
    int A[] = {1, 3, 5};
    int B[] = {2, 4, 6};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);

    mergeInPlace(A, B, n, m);

    printf("A = ");
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\nB = ");
    for(int i = 0; i < m; i++) printf("%d ", B[i]);
    printf("\n");

    return 0;
}
