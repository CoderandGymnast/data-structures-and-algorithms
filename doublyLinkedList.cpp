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
        if (k != position)
        {
            printf("[ERROR]: index out of bound");
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        return;
    }
}