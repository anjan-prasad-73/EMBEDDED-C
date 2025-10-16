/*13. Reordering by Parity Challenges
Question:
Write a C program to place all even-numbered nodes after odd-numbered nodes.

Sample data:
List: 1 2 3 4 5 6
Expected output:
Reordered list: 1 3 5 2 4 6*/


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

struct node* reorder_parity(struct node* head) 
{
    if (head == NULL)
        return NULL;

    struct node *oddstart = NULL, *oddend = NULL;
    struct node *evenstart = NULL, *evenend = NULL;
    struct node* curr = head;

    while (curr != NULL) 
    {
        if (curr->data % 2 != 0) 
        {
            if (oddstart == NULL) 
            {
                oddstart = oddend = curr;
            } 
            else 
            {
                oddend->next = curr;
                oddend = oddend->next;
            }
        } 
        else 
        {
            if (evenstart == NULL) 
            {
                evenstart = evenend = curr;
            } 
            else 
            {
                evenend->next = curr;
                evenend = evenend->next;
            }
        }
        curr = curr->next;
    }

    if (oddstart == NULL)
        return evenstart;

    oddend->next = evenstart;

    if (evenend != NULL)
        evenend->next = NULL;

    return oddstart;
}

int main() 
{
    struct node* head = NULL;
    int size, data;

    printf("enter number of nodes\n");
    scanf("%d", &size);

    printf("enter data for nodes\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &data);
        head = addend(head, data);
    }

    head = reorder_parity(head);

    printf("reordered list: ");
    printlist(head);

    return 0;
}
