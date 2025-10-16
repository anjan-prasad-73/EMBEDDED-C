//Apply dynamic memory to build a simple linked list.
#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    int roll;
    struct student* nxt;
}st;

void add_begin(st** ptr)
{
    st* temp=malloc(sizeof(st));
    printf("Enter the data:\n");
    scanf("%d",&temp->roll);

    temp->nxt = (*ptr);
    (*ptr) = temp;
}

void print(st* ptr)
{
    if(ptr!=NULL)
    {
        while(ptr)
        {
            printf("%d ",ptr->roll);
            ptr = ptr->nxt;
        }
    }
    else
    printf("Nothing is there\n");
    printf("\n");
}

void delete(st** ptr)
{
    st* temp;
    while((*ptr))
    {
        temp=(*ptr);
        (*ptr)=(*ptr)->nxt;
        free(temp);
        temp=NULL;
    }
}

int main()
{
    st* hptr=0;
    char op;
    do
    {
        add_begin(&hptr);
        printf("Do you want to add another node:\n");
        scanf(" %c",&op);
    } while (op=='y');
    print(hptr); 
    delete(&hptr);
    print(hptr);
}