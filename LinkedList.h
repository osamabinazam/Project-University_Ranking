#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include"Node.h"
#include<string>
#include<cstring>
#include <stdexcept>


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

    // Display List
    void Display (LinkedList<T>* list){
        Node<T>* current = list->head;
        char c;
        int count=1;
        while (current != nullptr)
        {
        bool flag=false;
           current->data->toString();
           if (count==50){
            count=1;
            cout<<"\n1. More Universities\n\nPress any key to \"Go BACK\"\nSelect an option: ";
            cin>>c;
            if (c=='1'){
                    continue;
                }
            else{
                    break;
                }
           }
           
           count++;
           current = current->next;
        }
        
    }


    // Delete a node from the list
    // Used when user is being deleted
    bool deleteNode (Node<T>* deleteNode){
           
        
        if (this->isEmpty()){
            
            return false;
        }
        else {
            if(deleteNode->next==nullptr)
            {
                deleteNode->prev=nullptr;
                this->size--;
                delete deleteNode;
            }
            else if(deleteNode->prev==nullptr)
            {
                this->size--;
                delete deleteNode;
            }
            else{
                deleteNode->next->prev=deleteNode->prev;
                deleteNode->prev->next=deleteNode->next;
                this->size--;
                delete deleteNode;

            }
        return true;
        }
       
    }
   

    //Sorting function to sort universites in decreasing order by their arscore, erscore, and fsrscore
    void sortDescending(University arr[], std::string factor, int length) {
    if (factor == "ar_score") {
        for (int i = 1; i < length; i++) {
            University key = arr[i];
           
            int j = i - 1;
            while (j >= 0 && stof(arr[j].arScore) < stof(key.arScore)) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    else if (factor == "er_score") {
        for (int i = 1; i < length; i++) {
            University key = arr[i];
            int j = i - 1;
            while (j >= 0 && stof(arr[j].erScore) < stof(key.erScore)) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        
    }
    else if (factor == "fsr_score") {
        for (int i = 1; i < length; i++) {
            University key = arr[i];
            int j = i - 1;
            while (j >= 0 && stof(arr[j].fsrScore) < stof(key.fsrScore)) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        
    }
}

    void recommendedUniversityies (LinkedList<T> * list, T topUnies[]){
        University Unies[list->size];
        listToArray(list, Unies);
        for (int i = 1; i < list->size; i++) {
            University key = Unies[i];
            int j = i - 1;
            while (j >= 0 && Unies[j].recommend < key.recommend  ) {
                Unies[j + 1] = Unies[j];
                j--;
            }
            Unies[j + 1] = key;
        }
        for (int i=0; i<10; i++){
            topUnies[i] = Unies[i];
        }
        

    };
    void listToArray(LinkedList<T>* list, T array[]){
        // University[] array = new University[list->size];
                Node<T>* current = list->head;
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




#endif