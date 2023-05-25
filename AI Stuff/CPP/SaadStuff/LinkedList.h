#include <iostream>
#include"Node.h"
#include<string>

using namespace std;
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
    void insert(University* data){
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

    void printUniversities (){
        Node* current = head;
        while (current != nullptr)
        {
           cout<<current->data->institute<<endl;
           current = current->next;
        }
        
    }


};