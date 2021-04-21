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

int main()
{
    // Solution I; 
    Node *head;
    Node instance = {"sonic", NULL};
    head = &instance;
    cout << head->data << endl;

    // Solution II: 
    Node *node = new Node();
    node->data = "sonic";
    cout << node->data << endl;
}