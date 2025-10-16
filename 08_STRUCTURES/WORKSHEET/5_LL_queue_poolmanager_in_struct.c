#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define POOL_SIZE 5

//--------------------------------------------------
// 1️⃣ Basic Dynamic Structure Allocation
//--------------------------------------------------
struct Student {
    int id;
    char name[30];
};

void demo_basic_allocation() {
    printf("\n--- [1] Basic Dynamic Structure Allocation ---\n");
    struct Student *ptr = (struct Student *)malloc(sizeof(struct Student));

    if (!ptr) {
        printf("Memory allocation failed!\n");
        return;
    }

    ptr->id = 101;
    strcpy(ptr->name, "Anjan");

    printf("Student ID: %d\n", ptr->id);
    printf("Student Name: %s\n", ptr->name);

    free(ptr);
    printf("Memory freed successfully.\n");
}

//--------------------------------------------------
// 2️⃣ Singly Linked List
//--------------------------------------------------
struct Node {
    int data;
    struct Node *next;
};

struct Node* create_node(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed for node!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void print_list(struct Node *head) {
    struct Node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void demo_linked_list() {
    printf("\n--- [2] Singly Linked List ---\n");

    struct Node *head = create_node(10);
    head->next = create_node(20);
    head->next->next = create_node(30);

    printf("Linked List: ");
    print_list(head);

    // Free all nodes
    struct Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("Linked list memory freed.\n");
}

//--------------------------------------------------
// 3️⃣ Queue Using Linked List
//--------------------------------------------------
struct QueueNode {
    int data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue *q, int value) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(struct Queue *q) {
    if (!q->front) {
        printf("Queue is empty!\n");
        return;
    }

    struct QueueNode *temp = q->front;
    q->front = q->front->next;

    if (!q->front)
        q->rear = NULL;

    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

void printQueue(struct Queue *q) {
    struct QueueNode *temp = q->front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void demo_queue() {
    printf("\n--- [3] Queue Using Dynamic Memory ---\n");
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Queue contents: ");
    printQueue(&q);

    dequeue(&q);
    printf("After dequeue: ");
    printQueue(&q);
}

//--------------------------------------------------
// 4️⃣ Memory Pool Manager (for fixed-size structures)
//--------------------------------------------------
struct Block {
    int data;
    bool used;
};

struct Block pool[POOL_SIZE];  // Static pool of blocks

void initPool() {
    for (int i = 0; i < POOL_SIZE; i++)
        pool[i].used = false;
}

struct Block* allocBlock() {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (!pool[i].used) {
            pool[i].used = true;
            return &pool[i];
        }
    }
    return NULL; // No free block
}

void freeBlock(struct Block* block) {
    block->used = false;
}

void demo_memory_pool() {
    printf("\n--- [4] Memory Pool Manager ---\n");
    initPool();

    struct Block *b1 = allocBlock();
    struct Block *b2 = allocBlock();

    if (b1 && b2) {
        b1->data = 100;
        b2->data = 200;
        printf("Allocated Blocks: %d, %d\n", b1->data, b2->data);
    }

    // Free one block and reuse it
    freeBlock(b1);
    printf("Block1 freed.\n");

    struct Block *b3 = allocBlock();
    if (b3)
        b3->data = 999;

    printf("Reused block data: %d\n", b3->data);
}

//--------------------------------------------------
// MAIN PROGRAM
//--------------------------------------------------
int main() {
    printf("======== Dynamic Memory with Structures (All-in-One Demo) ========\n");

    demo_basic_allocation();
    demo_linked_list();
    demo_queue();
    demo_memory_pool();

    printf("\nAll demonstrations complete.\n");
    return 0;
}
