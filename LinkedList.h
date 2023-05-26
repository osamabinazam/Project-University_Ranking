#include <iostream>
#include"Node.h"
#include<string>

using namespace std;
// Implement LinkedList 
template <typename T>
class LinkedList 
{
    public:
        Node<T>* head;
        Node<T>* tail;
        int size;

    // Constructor
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    bool isEmpty() {
        return (this->head==nullptr || this->tail==nullptr);
    }
    // Insert Node at the end of the List
    void insert(T* data){
        Node<T>* newNode = new Node<T>(data);
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


    bool SearchNode (string username){
        
    }

    void printUniversities (){
        Node<T>* current = head;
        while (current != nullptr)
        {
           cout<<current->data->institute<<endl;
           current = current->next;
        }
        
    }


};