#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

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
    if(position=1) {
        newNode->next=p;
        *head=newNode;
    } else {
        while((p!=NULL) && (k<position)) {
            k++;
            q=p;
            p=p->next;
        }
        q->next=newNode;
        newNode->next=p;
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