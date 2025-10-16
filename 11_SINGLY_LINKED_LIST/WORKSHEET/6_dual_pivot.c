/*6. Partitioning with Dual Pivots
Question:
Write a C program to partition a linked list around a value x.

Sample data:
List: 3 5 7 5 9 2 1
x = 5
Expected output:
Reordered list: 3 2 1 5 7 5 9*/



#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

void addend(struct node** head, int data) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void printlist(struct node* head) 
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node* partition(struct node* head, int x) 
{
    struct node *less_head = NULL, *less_tail = NULL;
    struct node *greater_head = NULL, *greater_tail = NULL;

    while (head != NULL) 
    {
        struct node* next = head->next;
        head->next = NULL;

        if (head->data < x) 
        {
            if (less_head == NULL) 
            {
                less_head = less_tail = head;
            } 
            else 
            {
                less_tail->next = head;
                less_tail = less_tail->next ;
            }
        } else {
            if (greater_head == NULL) 
            {
                greater_head = greater_tail = head;
            } 
            else 
            {
                greater_tail->next = head;
                greater_tail =greater_tail->next;
            }
        }

        head = next;
    }

    if (less_tail != NULL)
        less_tail->next = greater_head;

    return (less_head != NULL) ? less_head : greater_head;
}

int main() {
    struct node* head = NULL;

    int arr[] = {3, 5, 7, 5, 9, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        addend(&head, arr[i]);

    int x = 5;
    head = partition(head, x);

    printf("Reordered list: ");
    printlist(head);

    return 0;
}

