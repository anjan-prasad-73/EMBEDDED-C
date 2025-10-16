/*7. Linked List Addition Variants
Question:
Write a C program to add two numbers represented by linked lists.

Sample data:
List 1: 8 7 9 2
List 2: 2 1 2 3

Expected output:
Result: 0 9 1 6 (carry handled)*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addend(struct node** head, int data) {
    struct node* newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void addLists(struct node* l1, struct node* l2) {
   // l1 = reverseList(l1);
   // l2 = reverseList(l2);

    int carry = 0;

    printf("Sum: ");

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        
        printf("%d", sum);
    }

    printf("\n");
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* l1 = NULL;
    struct node* l2 = NULL;
    int n, val;

    printf("Enter number of digits in list 1: ");
    scanf("%d", &n);
    printf("Enter digits for list 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        addend(&l1, val);
    }

    printf("Enter number of digits in list 2: ");
    scanf("%d", &n);
    printf("Enter digits for list 2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        addend(&l2, val);
    }

    addLists(l1, l2);



    return 0;
}
