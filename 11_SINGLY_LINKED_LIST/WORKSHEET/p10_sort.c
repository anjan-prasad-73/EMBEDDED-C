/*10. Linked List Sorting Challenges
Question:
Write a C program to sort a singly linked list using merge sort.

Sample data:
List: 2 3 1 7 5

Expected output:
Sorted list: 1 2 3 5 7

*/




#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* addend(struct node* head, int data) {
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

void printlist(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void split(struct node* source, struct node** front, struct node** back) {
    struct node* slow = source;
    struct node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

struct node* merge(struct node* a, struct node* b) {
    struct node* result = NULL;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

struct node* merge_sort(struct node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct node* front;
    struct node* back;

    split(head, &front, &back);

    front = merge_sort(front);
    back = merge_sort(back);

    return merge(front, back);
}

int main() {
    struct node* head = NULL;
    int n, data;

    printf("enter number of nodes\n");
    scanf("%d", &n);

    printf("enter data for nodes\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = addend(head, data);
    }

    printf("original list:\n");
    printlist(head);

    head = merge_sort(head);

    printf("sorted list:\n");
    printlist(head);

    return 0;
}
