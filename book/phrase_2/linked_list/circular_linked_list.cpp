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
void insertAtMiddle(CLLNode **head, int data, int possition);
void deleteTheLast(CLLNode **head);
void deleteTheFirst(CLLNode **head);
void deleteNode(CLLNode **head, int i);

int main()
{
    // g++ -g circular_linked_list.cpp -o circular_linked_list.exe
    // gcc -g circular_linked_list.cpp -o circular_linked_list.exe
    // CLLNode**: Data structure.
    // *: Operator.
    // head: Pointer.
    CLLNode **head = (CLLNode **)malloc(sizeof(CLLNode *)); // head: [A] - [NULL]
    // printf("Address of head: %p\n", &head);
    // printf("Value of head: %p\n", head); // A
    // printf("Address of the space memory pointed by head: %p\n", &(*head)); // A
    *head = NULL;
    // printf("Value of *head: %p\n", (*head)); // B

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtBegin(head, 0);
    print(head);

    // deleteTheLast(head);
    // print(head);

    // deleteTheFirst(head);
    // print(head);

    deleteNode(head, 3);
    print(head);
    deleteNode(head, 3);
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

void insertAtMiddle(CLLNode **head, int data, int possition)
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

    int i = 1;
    while (i != possition)
        curr = curr->next;
    i++;

    newNode->next = curr->next;
    curr->next = newNode;
};

void deleteTheLast(CLLNode **head)
{
    CLLNode *curr, *temp = *head;

    if (!*head)
    {
        printf("List is empty");
        return;
    }

    while (curr->next != *head)
    {
        temp = curr;
        curr = curr->next;
    }
    temp->next = curr->next;
    free(curr);
}

void deleteTheFirst(CLLNode **head)
{
    CLLNode *curr, *temp = *head;
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }

    while (curr->next != *head)
    {
        curr = curr->next;
    }

    curr->next = temp->next;
    *head = temp->next;
    free(temp);
    return;
}

void deleteNode(CLLNode **head, int i)
{
    CLLNode *currNode = *head, *temp;

    if (!*head)
    {
        printf("[ERROR]: list empty");
        return;
    }

    for (int c = 0; c < i; c++)
    {
        temp = currNode;
        currNode = currNode->next;
        if (currNode == *head)
        {
            printf("[ERROR]: index out of bound");
            return;
        }
    }

    temp->next = currNode->next;
    free(currNode);
}
