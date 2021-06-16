#include<stdio.h>
#include<stdlib.h>
 
struct Block
{
    int numElements;
    int *nodes;
    struct Node *next;
};

int main() {
    Block** blockHead = (Block**) malloc(sizeof(Block*));
    *blockHead = (Block*) malloc(sizeof(Block));

    
}
 