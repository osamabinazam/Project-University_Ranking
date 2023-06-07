#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include "University.h"

template <typename T>
class Node {
    public:
        T* data;
        Node<T>* next;
        Node<T>* prev;

    // constructor

    Node (){
        data = new University();
        next = nullptr;
        prev = nullptr;
    }
    Node (T* d){
        this->data=d;
        this->next=nullptr;
        this->prev = nullptr;
    }

};
#endif