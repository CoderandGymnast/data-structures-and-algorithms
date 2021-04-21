#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node *next;
};

int main() {
   Node *head = (Node*) malloc(sizeof(Node));
   Node instance = {"sonic", NULL};
   head=&instance;
   cout << head->data << endl;
}