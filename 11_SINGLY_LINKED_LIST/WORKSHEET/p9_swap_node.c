/*9. Kth Node Swapping Variants
Question:
Write a C program to swap Kth node from beginning and end.

Sample data:
List: 1 2 3 4 5
k = 2 
Expected output:
Swapped list: 1 4 3 2 5*/



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

    struct node* last = head;
    while (last->next != NULL)
        last = last->next;

    last->next = temp;
    return head;
}

void print_list(struct node* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int count_nodes(struct node* head) 
{
    int count = 0;
    while (head) 
    {
        count++;
        head = head->next;
    }
    return count;
}

struct node* swap_kth_node(struct node* head, int k) 
{
    int n = count_nodes(head);
    if (k > n || 2 * k - 1 == n)
        return head;

    struct node* x = head;
    struct node* x_prev = NULL;
    for (int i = 1; i < k; i++) 
    {
        x_prev = x;
        x = x->next;
    }

    struct node* y = head;
    struct node* y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) 
    {
        y_prev = y;
        y = y->next;
    }

    if (x_prev)
        x_prev->next = y;
    else
        head = y;

    if (y_prev)
        y_prev->next = x;
    else
        head = x;

    struct node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    return head;
}

int main() {
    struct node* head = NULL;
    int n, data, k;

    printf("enter the number of nodes: ");
    scanf("%d", &n);

    printf("enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &data);
        head = addend(head, data);
    }

    printf("enter the value of k: ");
    scanf("%d", &k);

    printf("original list: ");
    print_list(head);

    head = swap_kth_node(head, k);

    printf("swapped list: ");
    print_list(head);

    return 0;
}
