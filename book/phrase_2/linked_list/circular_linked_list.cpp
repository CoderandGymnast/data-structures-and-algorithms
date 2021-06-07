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

    // CLLNode**: Data structure.
    // *: Operator.
    // head: Pointer.
    CLLNode** head = (CLLNode **)malloc(sizeof(CLLNode*)); // head: [A] - [B] - [...][...]
    printf("Address of head: %p\n", &head);
    printf("Value of head: %p\n", head); // A
    printf("Address of the space memory pointed by head: %p\n", &(*head)); // A
    * head = (CLLNode *)malloc(sizeof(CLLNode));
    printf("Value of *head: %p\n", (*head)); // B
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
