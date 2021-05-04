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
    if (position == 1)
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
    DLLNode* p = *head;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void DLLDelete(DLLNode **head, int position)
{
    DLLNode *p = *head;
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
            free(p);
            return;
        }
    }

    while (k < position && p->next != NULL)
    {
        p = p->next;
        k++;
    }

    if (k != position)
    {
        printf("[ERROR]: index out of bound");
        return;
    }

    p->prev->next = p->next;
    if(p->next) p->next->prev = p->prev;

    free(p);
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
