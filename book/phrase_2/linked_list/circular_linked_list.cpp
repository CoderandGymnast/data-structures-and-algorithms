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
void deleteLastNode(CLLNode **head);
void deleteFrontNode(CLLNode **head); 
void deleteNode(CLLNode **head, int i); 

int main()
{
    CLLNode **head = (CLLNode**)malloc(sizeof(CLLNode*));
    *head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtBegin(head, 0);
    print(head);

    // deleteLastNode(head);
    // print(head);

    // deleteFrontNode(head);
    // print(head);

    deleteNode(head, 3);
    print(head);
    deleteNode(head, 4);
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

    printf("\n");

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

void deleteLastNode(CLLNode **head) {
    // CLLNode* temp = *head, *current = *head;
    // if(!*head) {
    //     printf("[ERROR]: empty list");
    //     return;
    // }

    // while(current->next != *head) {
    //     temp = current;
    //     current = current->next;
    // }

    // temp->next = current->next;
    // free(current);
    // return;

    CLLNode* current = *head;
    if(!*head) {
        printf("[ERROR]: list empty");
        return;
    }

    while(current->next->next != *head) 
        current = current->next;

    current->next = current->next->next;
}

void deleteFrontNode(CLLNode **head) {
    CLLNode *temp = *head;
    CLLNode *current = *head;

    if(*head == NULL) {
        printf("[ERROR]: list empty");
        return;
    }

    while(current->next != *head) 
        current=current->next;

    current->next = (*head)->next;
    *head = (*head)->next;

    free(temp);
    return;

}

void deleteNode(CLLNode **head, int i) {
    CLLNode *currNode = *head, *temp;

    if(!*head) {
        printf("[ERROR]: list empty");
        return;
    }

    for(int c = 0; c < i ; c++) {
        temp = currNode;
        currNode = currNode->next;
        if(currNode == *head) {
            printf("[ERROR]: index out of bound");
            return;
        }
    }

    temp->next = currNode->next;
    free(currNode);
}