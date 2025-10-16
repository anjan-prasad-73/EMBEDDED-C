/*16. Alternate K-Node Reversal Challenges
Question:
Write a C program to reverse alternate k nodes.

Sample data:
List: 1 2 3 4 5 6 7 8
k = 2

Expected output:
Reversed: 2 1 3 4 6 5 7 8*/


#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

struct node* addend(struct node* head, int val) 
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) return temp;
    struct node* cur = head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = temp;
    return head;
}

void printlist(struct node* head) 
{
    struct node* cur = head;
    while (cur != NULL) 
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

struct node* reverse_alt_k(struct node* head, int k) 
{
    struct node* cur = head;
    struct node* prev = NULL;
    struct node* nxt = NULL;
    int count = 0;

    while (cur != NULL && count < k) 
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
        count++;
    }

    if (head != NULL)
        head->next = cur;

    count = 0;
    struct node* temp = cur;
    while (count < k - 1 && temp != NULL && temp->next != NULL) 
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL && temp->next != NULL)
        temp->next = reverse_alt_k(temp->next, k);

    return prev;
}

int main() {
    struct node* head = NULL;
    int n, val, k;
    printf("enter no nof nodes:");
    scanf("%d", &n);
    printf("enter node data:");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        head = addend(head, val);
    }
    printf("k:");
    scanf("%d", &k);

    head = reverse_alt_k(head, k);

    printlist(head);

    return 0;
}
