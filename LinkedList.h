#include <iostream>
#include"Node.h"
#include<string>
// #include"University.h"

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
    void Display (LinkedList<T>* list){
        Node<T>* current = list->head;
        while (current != nullptr)
        {
           current->data->toString();
           current = current->next;
        }
        
    }
    Node<T>* LinearSearchNode (string key){
        if (isEmpty()){
            cout<<"University List is empty!"<<endl;
            return NULL;
        }
        Node<T>* current = head;
        while (current != nullptr)
        {
            if (current->data->institute == key){
                return current;
            }
            current = current->next;  
        } 
    };

    Node<T>* SearchUser(string username){
        if (isEmpty()){
            cout<<"University List is empty!"<<endl;
            return NULL;
        }
        Node<T>* current = head;
        while (current != nullptr)
        {
            if (current->data->username == username){
                return current;
            }
            current = current->next;  
        } 
    };

    

    void listToArray(LinkedList<University>* list, University array[]){
        // University[] array = new University[list->size];
                Node<University>* current = list->head;
                int i = 0;
                while (current!= nullptr)
                {
                    array[i] = *current->data;
                    current = current->next;
                    i++;
                }
                // return array;
    }
};