#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};

void insert(Node **head, int data, int position)
{
    int counter = 1;
    Node *p, *newNode;

    newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("[ERROR]: out of memories\n");
        return;
    }

    newNode->data = data;
    p = *head;

    if (position == 1)
    {
        newNode->next = p;
        *head = newNode;
    }
    else
    {
        while ((p->next != NULL) && (counter < position - 1))
        {
            counter++;
            p = p->next;
        }
        if (counter < position-1)
        {
            printf("[ERROR]: index out of bound\n");
            return;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
}

void print(Node **head)
{
    Node *p = *head;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}


int main()
{
    Node **head = (Node **)malloc(sizeof(Node *));
    *head = (Node *)malloc(sizeof(Node));
    (*head)->data = 0;
    (*head)->next = NULL;
    insert(head, 10, 2);
    insert(head, 11, 3);
    insert(head, 12, 1);
    insert(head, 12, 6);
    print(head);
}