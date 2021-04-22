#include <stdio.h>
#include <stdlib.h>

struct DLLNode
{
    int data;
    DLLNode *next;
    DLLNode *prev;
};

void DLLInsert(DLLNode **head, int data, int position)
{
    int k = 1;
    DLLNode *temp, *newNode;
    newNode = (DLLNode *)malloc(sizeof(DLLNode));
    if (!newNode)
    {
        printf("[ERROR]: out of memories");
        return;
    }
    newNode->data = data;
    if (position == 1) // can use to init linked list.
    {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head)
        {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    else
    {

        temp = *head;
        while ((k < position - 1) && temp->next != NULL)
        {
            temp = temp->next;
            k++;
        }
        if (k != position - 1)
        {
            printf("[ERROR]: index out of bound\n");
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        return;
    }
}

void print(DLLNode **x)
{
    //printf("%p\n", &x);
    while (*x)
    {
        printf("%d\n", (*x)->data);
        *x = (*x)->next;
    }
}

int main()
{
    DLLNode **head = (DLLNode **)malloc(sizeof(DLLNode *));
    *head = (DLLNode *)malloc(sizeof(DLLNode));
    (*head)->data = 0;
    (*head)->prev = NULL;
    (*head)->next = NULL;

    DLLInsert(head, 1, 1);
    DLLInsert(head, 2, 2);
    DLLInsert(head, 3, 3);
    DLLInsert(head, 4, 4);
    //DLLInsert(head, 6, 7);

    //printf("%p\n", *head);
    //printf("%p\n", &(*head));
    //printf("%p\n", head);
    //printf("%p\n", &head);
    print(head);
    print(head);
}

// NOTE: head: [abc]->[xyz]->[...]