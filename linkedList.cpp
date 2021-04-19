#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int data;
    struct ListNode *next;
};

void deleteNodeFromLinkedList(ListNode**head, int pos) {
    int k = 1;
    ListNode* p, *q;
    if(*head==NULL) {
        printf("[ERROR]: list empty");
        return;
    }

    p=*head;
    if(pos==1) {
        *head = (*head)->next;
        free(p);
        return;
    }else {
        while((p!=NULL)&&(k<pos)) {
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL) {
            printf("[ERROR]: index out of bound");
        } else {
            q->next=p->next;
            free(p);
        }
    }
}

void printLinkedList(ListNode* head); // NOTE: Must put this after struct.
int ListLength(struct ListNode *head) {
    struct ListNode* current=head;
    int count=0;
    while(current!=NULL) {
        count++;
        current=current->next;
    }
    return count;
}

void InsertInLinkedList(struct ListNode **head,int data,int position) {
    int k=1;
    struct ListNode *p,*q,*newNode;
    newNode=(ListNode*)malloc(sizeof(struct ListNode));
    if(!newNode) {
        printf("out of memories");
        return;
    }
    newNode->data=data;
    p=*head;

    if(position==1) {
        newNode->next=p;
        *head=newNode;
    } else {
        while((p!=NULL) && (k<position)) {
            k++;
            q=p;
            p=p->next;
        }
        
    if(k<position) {
    printf("[ERROR]: index out of bound");
    return;
}

        q->next=newNode;
        newNode->next=p;
    }
}

void printLinkedList(ListNode* head) {
    ListNode* curr=head;
    while (curr)
    {
        printf("%d\n",curr->data);
        curr=curr->next;
    }
    
}

void insertAtTheBeginning(struct ListNode *head, struct ListNode *newNode) {
    newNode->next=head->next;
    head->next=newNode;
}

void insertAtTheEnd(struct ListNode *head, struct  ListNode *newNode) {
    struct ListNode* current=head;
    while(current->next!=NULL) {
        current=current->next;
    }
    newNode->next=NULL;
    current->next=newNode;
}

void insertAt(struct ListNode* head, struct ListNode *newNode, int pos) {
    ListNode *currNode=head;
    ListNode *posNode=currNode;
    ListNode *succNode=posNode->next;
    int counter=0;
    while(counter<pos) {
        counter++;
        currNode=currNode->next;
        posNode=currNode;
        succNode=posNode->next;
    }
    newNode->next=succNode;
    currNode->next=newNode;
}

int main() {
    ListNode** head=(ListNode**) malloc(sizeof(ListNode*));
    *head=(ListNode*) malloc(sizeof(ListNode));
    (*head)->data=0;
    (*head)->next=NULL;
    InsertInLinkedList(head, 1, 1);
    InsertInLinkedList(head, 2, 2);
    InsertInLinkedList(head, 3, 3);
    deleteNodeFromLinkedList(head, 1);
    deleteNodeFromLinkedList(head, 2);
    printLinkedList(*head);
    InsertInLinkedList(head,1,10);
    deleteNodeFromLinkedList(head, 4);
}

