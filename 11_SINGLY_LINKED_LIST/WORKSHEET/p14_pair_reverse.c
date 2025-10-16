/*
14. Pairwise Reversal Challenges
Question:
Write a C program to reverse nodes in pairs.

Sample data:
List: 1 2 3 4 5

Expected output:
Reversed in pairs: 2 1 4 3 5

*/



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

struct node* pairwise_reverse(struct node* head) 
{
    if (head == NULL || head->next == NULL)
        return head;

    struct node* prev = NULL;
    struct node* curr = head;
    struct node* new_head = head->next;

    while (curr != NULL && curr->next != NULL) 
    {
        struct node* next_pair = curr->next->next;
        struct node* second = curr->next;

        second->next = curr;
        curr->next = next_pair;

        if (prev != NULL)
            prev->next = second;

        prev = curr;
        curr = next_pair;
    }

    return new_head;
}

int main() {
    struct node* head = NULL;
    int n, data;

    printf("enter number of nodes\n");
    scanf("%d", &n);

    printf("enter data for nodes\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &data);
        head = addend(head, data);
    }

    head = pairwise_reverse(head);

    printf("reversed in pairs: ");
    printlist(head);

    return 0;
}
