#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// struct of a XORnode
struct XORnode
{
    /* data */
    int data;
    struct XORnode* link;    
};

// function to return XOR of "x" and "y"
struct XORnode* XOR(struct XORnode* x, struct XORnode* y)
{
    return(struct  XORnode*)((uintptr_t)(x) ^ (uintptr_t)(y));
};

// traverse the list in a foward direction
void traverse (struct XORnode* head)
{
    struct XORnode* curr = head;
    struct XORnode* pre = NULL;
    struct XORnode* next;

    while (curr != NULL)
    {
        printf("%d ->", curr->data);
        // calculate 'next'
        next = XOR(pre, curr->link);

        //update for the next loop
        pre = curr;
        curr = next;
    }
    printf("NULL");
}

//function to insert at the beginning
void pushfront(struct XORnode** head, int data)
{
    struct XORnode* newnode = (struct XORnode*)malloc(sizeof(struct XORnode));
    newnode->data = data;

    newnode->link = XOR(*head, NULL);

    if (*head)
    {
        (*head)->link = XOR(newnode, XOR((*head)->link, NULL));
    }

    *head = newnode;
}

void del(struct XORnode** head, int pos)
{
  
    // If list is empty
    if (*head == NULL)
        printf("List Is Empty");
    else {
        //Todo: tu head va null, tim dia chi node thu hai, update link cua node 2, tro head vao node 2, sau do xoa temp  
        if (pos == 0)
        {
            // Store the node to be deleted
            struct XORnode* temp = *head;
            // Update the head pointer
            (*head)->link = XOR(NULL, (temp)->link);
    
            // When the linked list contains only one node
            if (*head != NULL) 
            {
                // Update head node address
                (*head)->link = XOR(NULL, XOR(temp, (*head)->link));
            }
    
            free(temp);
        }
        else
        {
            int move = 0;
            struct XORnode* pre = NULL;
            struct XORnode* curr = *head;
            struct XORnode* nextdel;
            struct XORnode* next1;
            struct XORnode* next2;
            struct XORnode* next3;            

            while (move < pos - 1)
            {
                nextdel = XOR(pre, (curr)->link);
                pre = curr;
                curr = nextdel;
                move+=1; 
            }
            nextdel = XOR(pre, (curr)->link);
            next1 = XOR(curr, (nextdel)->link);
            next2 = XOR(nextdel, (next1)->link);
            // next3 = XOR(next2, (next1)->link);
            curr->link = XOR(pre, next1);
            next1->link = XOR(curr, next2);


            free(nextdel);
        }
    }
}

int main(void)
{
    int keys[] = {21,0,8,1,9,99};
    int n = sizeof(keys)/sizeof(keys[0]);

    struct XORnode* head = NULL;
    for (int i = n-1; i>=0; i--)
    {
        pushfront(&head, keys[i]);
    }
    
    traverse(head);
    del(&head, 3);
    traverse(head);
    return(0);
}