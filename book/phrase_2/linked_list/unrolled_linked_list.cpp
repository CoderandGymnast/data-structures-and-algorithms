#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 4 

struct Node {
    int data;
    Node *next;
};
 
struct Block
{
    int maxNodes;
    int numNodes;
    Node *head;
    Block *next;
};

void insert(Block** blockHead, int pos, int data); 


int main() {
    Block** blockHead = (Block**) malloc(sizeof(Block*));
    *blockHead = NULL;
    insert(blockHead, 0, 0);
    insert(blockHead, 2,2);
}

void print(Block** blockHead) {
    Block* currHead = *blockHead;
    while(currHead) { // currHead != null, process the block.
        // TODO: print list.
    }
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
        if(pos) {
            printf("[ERROR]: index out of bound - max index: 0");
            return;
        }
        *blockHead = (Block*) malloc(sizeof(Block));
        (*blockHead)->maxNodes = BLOCK_SIZE;  
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
            // - Insert to the last. (Need to test "index out of bound - max index.")
            int blockPos = pos - (numScan - BLOCK_SIZE);
            if(blockPos + 1 > currBlock->numNodes) {
                printf("[ERROR]: index out of bound - max index: %d", (numScan - BLOCK_SIZE + currBlock->numNodes));
                return;
            }
            if(currBlock->numNodes < currBlock->maxNodes) {
                int count = 0;
                Node* currNode = currBlock->head;
                while(count < blockPos - 1) {
                    currNode = currNode->next;
                }
            } else if(currBlock->numNodes == currBlock->maxNodes) {


            }


            return;
        }

        currBlock = currBlock->next;
    }
    
    printf("[ERROR]: index out of bound");
}