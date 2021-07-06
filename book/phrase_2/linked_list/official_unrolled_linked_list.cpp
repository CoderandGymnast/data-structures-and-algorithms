#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

int blockSize; // Max number of nodes in a block

struct Node
{
    Node *next;
    int value;
};

struct Block
{
    Block *next;
    Node *head;
    int nodeCount;
};

Block *headBlock;

Block *initBlock()
{
    Block *block = (Block *)malloc(sizeof(Block));
    block->next = NULL;
    block->head = NULL;
    block->nodeCount = 0;
    return block;
}

Node *initNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

void search(int pos, Block **outBlock, Node **outNode)
{
    int i = (pos + blockSize - 1) / blockSize; //Pos - th node is in the i-th block.
    Block *p = headBlock;
    while (--i)
        p = p->next;
    *outBlock = p;
    Node *q = p->head;
    pos = pos % blockSize;
    if (pos == 0)
        pos = blockSize;
    pos = p->nodeCount + 1 - pos;
    while (pos--)
        q = q->next;
    *outNode = q;
}

void shift(Block *A)
{
    Block *B;
    Node *temp;
    while (A->nodeCount > blockSize)
    {
        if (!A->next)
        {
            A->next = initBlock();
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            B->head = temp;
            temp->next = temp;
            A->nodeCount--;
            B->nodeCount++;
        }
        else
        {
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            temp->next = B->head->next;
            B->head->next = temp;
            B->head = temp; // [WARNING]: ?
            A->nodeCount--;
            B->nodeCount++;
        }
        A = B;
    }
}

void addElement(int k, int x)
{
    Node *p, *q;
    Block *r;
    if (!headBlock)
    {
        headBlock = initBlock();
        headBlock->head = initNode(x);
        headBlock->head->next = headBlock->head;
        headBlock->nodeCount++;
    }
    else
    {
        if (k == 0)
        {
            Node* newHead=initNode(x);
            newHead->next=headBlock->head;
            Node* currHead=headBlock->head;
            Node* slideNode=currHead;
            while(slideNode->next!=currHead) slideNode=slideNode->next;
            slideNode->next=newHead;
            headBlock->head=newHead;
            headBlock->nodeCount++;
            shift(headBlock);
        }
        else
        {
            search(k, &r, &p);
            q = p;
            while (q->next != p)
                q = q->next;
            q->next = initNode(x);
            q->next->next = p;
            r->nodeCount++;
            shift(r);
        }
    }
}

int searchElement(int k)
{
    Node *p;
    Block *q;
    search(k, &q, &p);
    return p->value;
}

void print()
{
    Block *curBlock = headBlock;
    Node *curNode, *headNode;
    int cnt = 0;
    while (curBlock)
    {
        printf("Block no. %d: ", ++cnt);
        headNode = curBlock->head;
        curNode = headNode;
        do
        {
            printf("%d ", curNode->value);
            curNode = curNode->next;
        } while (curNode != headNode);
        curBlock = curBlock->next;
        return;
        printf("\n");
    }
}

int main()
{
    blockSize =2;
addElement(0, 0);
addElement(0,1);
addElement(0,2);
/* TODO: 
* Add more elements than the block size of the head block at position 0.
* Add position != 0 (Hint: Errors in the code block k!=0).
*/

    print();
}