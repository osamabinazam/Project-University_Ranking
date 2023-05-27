#include <iostream>
#include"Node.h"
#include<string>
#include<cstring>
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

    // Display List
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
        
        bool found = false;
        if (isEmpty()){
            cout<<"User list is empty"<<endl;
            return NULL;
        }
        Node<T>* current = head;
        
        int count = 1;
        while (current != nullptr && count<=this->size)
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
    //Binary serach
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
                cout << array[mid].institute << endl;
                cout << array[mid].arRank << endl;
                cout << array[mid].arScore << endl;
                cout << array[mid].location << endl;
                cout << array[mid].gerRank << endl;
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

        // Key not found
        return nullptr;
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
        
        for (int i = 0; i < length; i++) {
            std::cout << i << "- " << arr[i].arScore << std::endl;
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
        
        for (int i = 0; i < length; i++) {
            std::cout << i << "- " << arr[i].erScore << std::endl;
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
        
        for (int i = 0; i < length; i++) {
            std::cout << i << "- " << arr[i].fsrScore << std::endl;
        }
    }
}


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



