#include <iostream>
#include"Node.h"
// Implement LinkedList 
class LinkedList
{
    public:
        Node* head;
        Node* tail;
        int size;

    // Constructor
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // Insert Node at the end of the List
    void insert(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            size++;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            size++;
        }

    }


};