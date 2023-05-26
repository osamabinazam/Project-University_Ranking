#include "University.h"

template <typename T>
class Node {
    public:
        T* data;
        Node<T>* next;
        Node<T>* prev;

    // constructor
    Node (T* d){
        this->data=d;
        this->next=nullptr;
        this->prev = nullptr;
    }

};