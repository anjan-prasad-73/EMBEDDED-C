/*15. Block Reversal Variants
Question:
Write a C program to reverse nodes in blocks of size k.

Sample data:
List: 1 2 3 4 5 6
k = 3
 
Expected output:
Reversed: 3 2 1 6 5 4*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* addend(struct node* head, int data) 
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    struct node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}

void printlist(struct node* head) 
{
    struct node* curr = head;
    while (curr != NULL) 
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct node* reverse_block(struct node* head, int k) 
{
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    int count = 0;


    while (curr != NULL && count < k) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    
    if (next != NULL)
        head->next = reverse_block(next, k);

    return prev;
}

int main() 
{
    struct node* head = NULL;
    int n, data, k;

    printf("enter number of nodes\n");
    scanf("%d", &n);

    printf("enter data for nodes\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &data);
        head = addend(head, data);
    }

    printf("enter block size k\n");
    scanf("%d", &k);

    head = reverse_block(head, k);

    printf("reversed: ");
    printlist(head);

    return 0;
}
