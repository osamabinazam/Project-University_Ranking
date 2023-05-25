
class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    // constructor
    Node (int d){
        this->data=d;
        this->next=nullptr;
        this->prev = nullptr;
    }

};