#include <iostream>
#include<string>
#include<cstring>
#include "University.h"
#include "Users.h"
#include "Feedback.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;



University binarySearch(University array[], int size, string key)
    {
        int low = 0;
        int high = size - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Use the string comparison function (strcmp) to compare sentences
            int compareResult = strcmp(array[mid].institute.c_str(), key.c_str());

            if (compareResult == 0)
            {
                // Key found at index mid
                return array[mid];
            }
            else if (compareResult < 0)
            {
                // array[mid].institute < key
                low = mid + 1;
            }
            else
            {
                // array[mid].institute > key
                high = mid - 1;
            }
        }
        University uni ;
        // Key not found
        return uni;
}


    // Linear Search
    Node<University>* linearSearchNode (LinkedList<University> * list , string key){
        if (list->isEmpty()){
            cout<<"University List is empty!"<<endl;
            return nullptr;
        }

        Node<University>* current = list->head;
        int count = 0;
        
        while (current != nullptr && count <= list->size)
        {
            if (current->data->institute == key){
                return current;
            }
            current = current->next;  
            count++;
        } 
        Node<University>* newNode = new Node<University>();
        return newNode;
}

Node<User>* SearchUser(LinkedList<User> * userlist,string username){
        
        bool found = false;
        if (userlist->isEmpty()){
            cout<<"User list is empty"<<endl;
            return NULL;
        }
        Node<User>* current = userlist->head;
        
        int count = 1;
        while (current != nullptr && count<=userlist->size)
        {
            
            
            if (current->data->username == username){
                
                found = true;
                return current;
            }
            current = current->next; 
            count++; 
        }
       
        return nullptr; 
    };