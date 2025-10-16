//Write a C program to merge K sorted linked lists.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } 
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}

Node* mergeKLists(Node* lists[], int k) {
    if (k == 0) 
    return NULL;

    while (k > 1) {
        int i = 0;
        for (; i < k / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
        }
        k = (k + 1) / 2;
    }

    return lists[0];
}

int main() 
{
    Node* list1 = newNode(10);
    list1->next = newNode(20);
    list1->next->next = newNode(50);

    Node* list2 = newNode(30);
    list2->next = newNode(40);
    list2->next->next = newNode(60);

    Node* list3 = newNode(10);
    list3->next = newNode(70);
    list3->next->next = newNode(100);

    Node* lists[3] = {list1, list2, list3};

    Node* mergedList = mergeKLists(lists, 3);

    printf("Merged list: ");
    printList(mergedList);

    return 0;
}
