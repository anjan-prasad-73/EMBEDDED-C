/*3. Palindrome Check Variants
Question:
Write a C program to check if a singly linked list is a palindrome.

Sample data:
List: 1 2 2 1

Expected output:
Linked list is a palindrome.*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void add_node(struct node** head, int value) 
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) 
    {
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void print_list(struct node* head) 
{
    struct node* temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* reverse_list(struct node* head) 
{
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next;

    while (curr != NULL) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int is_palindrome(struct node* head) 
{
    if (head == NULL || head->next == NULL)
        return 1;

    struct node *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) 
    {
        
        slow = slow->next;
        fast = fast->next->next;
    }

    
    struct node* second_half = reverse_list(slow->next);
    struct node* first_half = head;
    struct node* temp = second_half;
    int result = 1;

    while (temp != NULL) 
    {
        if (first_half->data != temp->data) 
        {
            result = 0;
            break;
        }
        first_half = first_half->next;
        temp = temp->next;
    }

    slow->next = reverse_list(second_half);  
    return result;
}

int main() 
{
    struct node* head = NULL;
    int n, value;

    printf("enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements:\n", n);

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        add_node(&head, value);
    }

    printf("list: ");
    print_list(head);

    if (is_palindrome(head))
        printf("linked list is a palindrome.\n");
    else
        printf("linked list is not a palindrome.\n");

    return 0;
}

