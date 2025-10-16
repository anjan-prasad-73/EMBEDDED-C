/*11. Nth Node from End Variants
Question:
Write a C program to retrieve the nth node from the end.

Sample data:
List: 1 3 5 11
n = 3

Expected output:
Result: 3*/

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

int nth_from_end_brute(struct node* head, int n) 
{
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }

    if (n > count)
        return -1;

    int target = count - n + 1;
    temp = head;
    for (int i = 1; i < target; i++) 
    {
        temp = temp->next;
    }

    return temp->data;
}

int main() 
{
    struct node* head = NULL;
    int size, data, n;

    printf("enter number of nodes\n");
    scanf("%d", &size);

    printf("enter data for nodes\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &data);
        head = addend(head, data);
    }

    printf("enter n\n");
    scanf("%d", &n);

    int result = nth_from_end_brute(head, n);
    if (result == -1)
        printf("n is larger than the list size\n");
    else
        printf("result: %d\n", result);

    return 0;
}
