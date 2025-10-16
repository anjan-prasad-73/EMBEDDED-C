/*17. Halving the List Challenges
Question:
Write a C program to split a list into two halves.

Sample data:
List: 1 2 3 4 5 6

Expected output:
First half: 1 2 3
Second half: 4 5 6
*/



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
    if (head == NULL) 
      return temp;
    struct node* cur = head;
    while (cur->next != NULL) 
    cur = cur->next;
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

void split_list(struct node* head, struct node** first, struct node** second) 
{
    struct node* slow = head;
    struct node* fast = head;
    struct node* prev = NULL;

    while (fast != NULL && fast->next != NULL) 
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) 
      prev->next = NULL;

    *first = head;
    *second = slow;
}

int main() 
{
    struct node* head = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
    int n, val;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        head = addend(head, val);
    }

    split_list(head, &first, &second);

    printf("First half: ");
    printlist(first);
    printf("Second half: ");
    printlist(second);

    return 0;
}
