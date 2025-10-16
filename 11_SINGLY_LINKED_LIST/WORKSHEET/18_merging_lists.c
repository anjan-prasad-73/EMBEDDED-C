//Write a C program to merge alternate nodes of two linked lists.
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

Node* interleaveLists(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;

        tail->next = l2;
        l2 = l2->next;
        tail = tail->next;
    }

    if (l1) 
    tail->next = l1;
    if (l2)
    tail->next = l2;

    return dummy.next;
}

int main() 
{
    Node* list1 = newNode(9);
    list1->next = newNode(7);
    list1->next->next = newNode(5);

    Node* list2 = newNode(10);
    list2->next = newNode(8);
    list2->next->next = newNode(6);

    Node* result = interleaveLists(list1, list2);

    printf("Result: ");
    printList(result);

    return 0;
}
