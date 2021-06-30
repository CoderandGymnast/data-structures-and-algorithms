#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int blockSize; // Max number of nodes in a block

struct Node {
    Node*next;
    int value;
};

struct Block
{
    Block*next;
    Node*head;
    int nodeCount;
};

Block* headBlock;

Block* initBlock(){
    Block* block=(Block*) malloc(sizeof(Block));
    block->next=NULL;
    block->head=NULL;
    block->nodeCount=0;
    return block;
}

Node* initNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->next=NULL;
    node->value=value;
    return node;
}

void search(int pos, Block**outBlock, Node*outNode) {
    int i=(pos+blockSize-1)/blockSize; //Pos - th node is in the i-th block.
    Block*p=headBlock;
    while(--i)p=p->next;
    *outBlock=p;
    Node*q=p->head;
    pos=pos%blockSize;
    if(pos==0)pos=blockSize;
    pos=p->nodeCount+1-pos;
    while(pos--)q=q->next;
    outNode=q;
}

void shift(Block*A) {
    Block*B;
    Node*temp;
    while(A->nodeCount>blockSize) {
        if(!A->next){
            A->next=initBlock();
            B=A->next;
            temp=A->head->next;
            A->head->next=A->head->next->next;
            B->head=temp;
            temp->next=temp;
            A->nodeCount--;
            B->nodeCount++;
        }
    }
}

int main() {
    printf("%d", 3/5);
}