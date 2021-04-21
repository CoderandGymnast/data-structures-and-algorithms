#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct Node
{
    int i;
    string data;
    Node *next;
};

int main()
{
    // Solution I; 
    Node *head; // Declaration; Variable is a memory space.
    cout << &(head) << endl; // Pointer address. 
    cout << &(*head) << endl; // Pointer data; Address of data.

    head->i=10;
    cout << head->i << endl;
    head->data="123"; 
    cout << head->data << endl;

    Node instance = {1,"sonic", NULL};
    head = &instance;
    cout << head->data << endl;

    // Solution II: 
    Node *node = new Node();
    node->data = "sonic";
    cout << node->data << endl;
}