// First experrient with LinkedList 

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

using namespace std;

struct Node{
	char* data;
	Node *next;
};

//void Insert(struct Node **head, int data, int position){
//	int k = 1;
//	struct Node *p, *q, *newNode;
//	newNode = (Node *)malloc(sizeof(struct Node));
//	if(!newNode){
//		printf("Memory Error");
//		return;
//	}
//	
//	newNode->data = data;
//	p = *head;
//	
//	//Insert at the beginning
//	if(position ==1){
//		newNode->next = p;
//		*head = newNode;
//	}
//	else{
//		//Traverse the link until the position where we want to insert
//		while((p!=NULL)&&(k<position)){
//			k++;
//			q = p;
//			p = p->next;
//		}
//		q->next = newNode;
//		newNode->next = p;
//	}	
//}


int main(){

	Node** head = (Node**) malloc(sizeof(Node*));
	Node* first = (Node*) malloc(sizeof(Node));

	*head=first;

	Node* second = (Node*) malloc(sizeof(Node));

	Node* third = (Node*) malloc(sizeof(Node));
	
	first->data = (char*) malloc(255*sizeof(char));
	strcpy(first->data, "VU");
	first->next = second;
	
		second->data = (char*) malloc(255*sizeof(char));
strcpy(second->data, "DUY");
	second->next = third;
	
	third->data = (char*) malloc(255*sizeof(char));
		strcpy(third->data, "THIEN");
	third->next = NULL;
	
	//Print LinkedList
	Node* currNode = *head;
	while (currNode!=NULL){
		printf("%s", currNode->data);
		currNode = currNode->next;
	}
	
//	Node* extra = NULL;
//	extra = new Node();
//	extra->data = "Ho va ten: ";

	//Insert(first, "Ho va ten: ", 1);
	
	return 0;	
}