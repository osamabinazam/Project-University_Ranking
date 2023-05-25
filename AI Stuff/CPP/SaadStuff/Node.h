#include "University.h"

class Node {
    public:
        University* data;
        Node* next;
        Node* prev;

    // constructor
    Node (University* d){
        this->data=d;
        this->next=nullptr;
        this->prev = nullptr;
    }

};