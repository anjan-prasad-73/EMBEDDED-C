#include <stdio.h>

int main() {
    int arr[5]={1,2,3,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i=0,f;
    int j=size-1;
    while(i<j)
    {
      if(arr[i]!=arr[j])
      {
        f=1;
      }
      i++;
      j--;
    }

    if(!f) printf("The array is a palindrome.\n");
    else printf("The array is not a palindrome.\n");

    return 0;
}
