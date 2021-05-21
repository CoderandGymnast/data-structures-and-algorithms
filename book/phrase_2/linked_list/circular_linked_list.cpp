#include <stdio.h>
#include <stdlib.h>

struct CLLNode
{
    int data;
    CLLNode *next;
};

int len(CLLNode *head);
void print(CLLNode *head);

int main()
{
    CLLNode *head = (CLLNode *)malloc(sizeof(CLLNode));
    head->data = 1;
    head->next = head;

    int numNodes = len(head);
    printf("Length: %d\n", numNodes);
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

void print(CLLNode *head)
{
    CLLNode *curr = head;
    if (head == NULL)
        return;
    do
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    } while (curr != head);
}