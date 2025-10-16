//Write a C program to swap every two adjacent nodes.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* swapPairs(Node* head) {
    if (!head || !head->next)
        return head;

    Node* dummy = newNode(0);
    dummy->next = head;
    Node* prev = dummy;

    while (prev->next && prev->next->next) {
        Node* first = prev->next;
        Node* second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    Node* newHead = dummy->next;
    free(dummy);
    return newHead;
}

int main() 
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original list:\n");
    printList(head);

    head = swapPairs(head);

    printf("Swapped list:\n");
    printList(head);

    return 0;
}
