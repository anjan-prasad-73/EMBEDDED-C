/*1. Merge Sorted Lists Challenges
Question:
Write a C program to merge two sorted singly linked lists into a single sorted linked list.

Sample data:
List 1: 1 3 5 7
List 2: 2 4 6 
Expected output:
Merged list: 1 2 3 4 5 6 7*/



#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void addend(struct node** head, int data) 
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL) 
    {
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
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node* mergesorted(struct node* l1, struct node* l2) 
{
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) 
    {
        if (l1->data < l2->data) 
        {
            tail->next = l1;
            l1 = l1->next;
        } 
        else 
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) 
     tail->next = l1;
    else 
     tail->next = l2;

    return dummy.next;
}

int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    int n1, n2, value;

    printf("Enter the number of elements in list 1: ");
    scanf("%d", &n1);
    printf("list 1:\n", n1);
    for (int i = 0; i < n1; i++) 
    {
        scanf("%d", &value);
        addend(&list1, value);
    }

    printf("Enter the number of elements in list 2: ");
    scanf("%d", &n2);
    printf("list 2:\n", n2);
    for (int i = 0; i < n2; i++) 
    {
        scanf("%d", &value);
        addend(&list2, value);
    }

    struct node* mergedlist = mergesorted(list1, list2);

    printf("Merged list: ");
    printlist(mergedlist);
    printf("\n");

    return 0;
}
