#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 3

struct Node {
    int data;
    Node *next;
};
 
struct Block
{
    int numNodes;
    Node *head;
    Block *next;
};



int main() {
    Block** blockHead = (Block**) malloc(sizeof(Block*));
    *blockHead = NULL;
}

void insert(Block** blockHead, int pos, int data) {
    
    Block *currBlock = *blockHead;
    
    // 1. Create new node:
    Node* newNode = (Node*) malloc(sizeof(Node));

    if(!newNode) {
        printf("[ERROR]: out of memory");
        return;
    }

    newNode->data = data;

    // 2. Insert to an empty list:
    if(!*blockHead) {
        *blockHead = (Block*) malloc(sizeof(Block));
        (*blockHead)->numNodes = 1;
        (*blockHead)->next = NULL;
        (*blockHead)->head = newNode;
        newNode->next = newNode;
        return;
    }

    // 3. Insert to non-empty list:
    int numScan = 0;
    while (currBlock->next)
    {

        numScan += currBlock->numNodes;
        if(pos + 1 - numScan <= 0) {

            // 4. Insert to the suitable block:
            // TODO: 
            // - Insert to the last.
            // - Index out of bound when the list is empty.

            return;
        }

        currBlock = currBlock->next;
    }
    
    printf("[ERROR]: index out of bound");
}