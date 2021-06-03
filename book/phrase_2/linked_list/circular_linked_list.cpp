#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

struct CLLNode
{
    int data;
    CLLNode *next;
};

int len(CLLNode *head);
void print(CLLNode **head);
void insertAtEnd(CLLNode **head, int data);
void insertAtBegin(CLLNode **head, int data);

int main()
{
    // CLLNode **head = (CLLNode **)malloc(sizeof(CLLNode *));
    // *head = (CLLNode *)malloc(sizeof(CLLNode));
    // (*head)->data = 0;
    // (*head)->next = *head;

    // if (*head == NULL) printf("*head is NULL");
    // else printf("*head is not NULL");
    // cout << "*head: " << *head << endl;
    CLLNode **head = (CLLNode **)malloc(sizeof(CLLNode *));
    *head = NULL;
    cout << "*head: " << *head << endl;
    insertAtEnd(head, 1);
    insertAtBegin(head, -1);
    print(head);
}

/* Use address to determine the end of circular linked list. */
int len(CLLNode *head)
{
    CLLNode *curr = head;
    int count = 0;
    if (head == NULL)
        return 0;
    do
    {
        curr = curr->next;
        count++;
    } while (curr != head);

    return count;
}

void print(CLLNode **head)
{
    CLLNode *curr = *head;
    if (head == NULL)
        return;
    do
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    } while (curr != *head);
}

void insertAtEnd(CLLNode **head, int data)
{
    // The point is to use the address of *head.

    CLLNode *curr = *head;
    CLLNode *newNode = (CLLNode *)malloc(sizeof(CLLNode));

    if (!newNode)
    {
        printf("[ERROR]: out of memory");
        return;
    }

    newNode->data = data;
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    while (curr->next != *head)
        curr = curr->next;

    newNode->next = *head;
    curr->next = newNode;
}

void insertAtBegin(CLLNode **head, int data)
{
    CLLNode *currNode = *head;
    CLLNode *newNode = (CLLNode *)malloc(sizeof(CLLNode));

    if (!newNode)
    {
        printf("[ERROR]: out of memory");
        return;
    }

    newNode->data = data;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    while (currNode->next != *head)
        currNode = currNode->next;

    newNode->next = *head;
    currNode->next = newNode;
    *head = newNode;
}
