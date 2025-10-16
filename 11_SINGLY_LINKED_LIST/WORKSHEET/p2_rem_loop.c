/*2. Loop Detection Challenges
Question:
Write a C program to detect and remove a loop in a singly linked list.

Sample data:
List: 1 → 2 → 3 → 4 → 5 → (loop to 2)
Expected output:
Loop detected and removed.
List after removal: 1 2 3 4 5

*/



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
    struct node* temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int removeloop(struct node* head) 
{
    struct node *slow = head, *fast = head;

    while (slow && fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) 
        {
            struct node* ptr1 = head;
            struct node* ptr2 = slow;

            if (ptr1 == ptr2) 
            {
                while (ptr2->next != ptr1)
                    ptr2 = ptr2->next;
                ptr2->next = NULL;
            } 
            else 
            {
                while (ptr1->next != ptr2->next) 
                {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                ptr2->next = NULL;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    struct node* head = NULL;

    addend(&head, 1);
    addend(&head, 2);
    addend(&head, 3);
    addend(&head, 4);
    addend(&head, 5);

    head->next->next->next->next->next = head->next;

    if (removeloop(head)) 
    {
        printf("Loop detected and removed.\n");
    } 
    else 
    {
        printf("No loop found.\n");
    }

    printf("List after removal: ");
    printlist(head);

    return 0;
}
