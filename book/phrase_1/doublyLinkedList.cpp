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

void print(DLLNode **head)
{
    //printf("%p\n", &x);
    DLLNode* p = *head;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void DLLDelete(DLLNode **head, int position)
{
    DLLNode *temp, *temp2;
    temp = *head;
    int k = 1;
    if (*head == NULL)
    {
        printf("[ERROR]: list empty");
        return;
    }
    if (position == 1)
    {
        *head = (*head)->next;


        if (*head != NULL)
        {
            (*head)->prev = NULL;
            free(temp);
            return;
        }
    }

    while (k < position && temp->next != NULL)
    {
        temp = temp->next;
        k++;
    }

    if (k != position)
    {
        printf("[ERROR]: index out of bound");
        return;
    }

    temp2 = temp->prev;
    temp2->next = temp->next;

    if (temp->next)
        temp->next->prev = temp2;
    free(temp);
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

    DLLDelete(head, 1);
    printf("...\n");
    print(head);


    DLLDelete(head, 2);
    printf("...\n");
    print(head);


    DLLDelete(head, 3);
    printf("...\n");
    print(head);

    DLLDelete(head, 3);
}

// NOTE: head: [abc]->[xyz]->[...]