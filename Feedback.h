#ifndef FEEDBACK_H
#define FEEDBACK_H


#include<iostream>
#include<string>
#include"Users.h"
class Feedback{
    public:
        User user;
        string feedback;
        string title;
        string reply;
        University uni;
        string feedback_date;

        Feedback(){
            this->feedback="";
            this->reply="";
            this->feedback_date="";

        }
        Feedback(User user, string feedback, University uni, string title, string feedback_date) {
            this->user = user;
            this->feedback = feedback;
            this->uni=uni;
            reply="";
            this->title=title;
            this->feedback_date = feedback_date;
        }
};

class FeedbackNode {
    public:
        Feedback data;
        FeedbackNode *next;
        FeedbackNode *prev;

        FeedbackNode(){
            next = NULL;
            prev = NULL;
            // this->data=NULL
        }

        FeedbackNode(Feedback* data){
            this->data = *data;
            this->next = NULL;
            this->prev= NULL;
            this->data.reply="";
        }

        void displayFeedback(){
            cout<<"============================================================================================\n";
            cout<<"Feedback Date: "<<this->data.feedback_date<<endl;
            cout<<"Feedback User: "<<this->data.user.name<<endl;
            cout<<"Feedback Title: "<<this->data.title<<endl;
            cout<<"Feedback: "<<this->data.feedback<<endl;
            cout<<"============================================================================================\n";

        }
        void displayReply(){
            cout<<"============================================================================================\n";
            cout<<"University Name : "<<this->data.uni.institute<<endl;
            cout<<"Title of the Feedback : "<<this->data.title<<endl;
            cout<<"Reply : "<<this->data.reply<<endl;
            cout<<"============================================================================================\n";
        }
};

// Feedback Class Implements LinekedList
class FeedbackList{
    public:
        FeedbackNode *head;
        FeedbackNode *tail;
        int size;
        FeedbackList(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        bool isEmpty(){
            return (head == NULL && tail == NULL);

        }
        void insert(Feedback* data){
            FeedbackNode* newNode = new FeedbackNode(data);
            if (isEmpty()){
                head = newNode;
                tail = newNode;
                size++;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
                size++;
            }
        }

        void displayFeedbacks(){
            if (isEmpty()) {
                cout<<"There is no Feedback to display\n";
            }
            else {
                FeedbackNode* current = this->head;
                char ch;
                string message="";
                while (current != nullptr)
                {
                    current->displayFeedback();
                    cout<<"\n Do you want to reply ? (Y/N),(y/n) : ";
                    cin>>ch;
                    if (ch == 'Y' || ch == 'y'){
                        cout<<"\n Enter reply : ";
                        cin>>message;
                        current->data.reply = message;
                    }
                    else {
                        continue;
                    }
                }
                
            }
        }

        void displayFeedbackReply(User *user){
            
            bool flag;
            if (this->isEmpty()){
                flag=true;
            }
            flag=true;
            FeedbackNode *current = head;
            while (current != NULL)
            {
                if (user->username == current->data.user.username){
                    current->displayReply();
                    flag= false;
                }
                current = current->next;
            }
            if (flag){
                cout<<"There is no feedback reply...."<<endl;
            }
        }

        void displayFeedback (FeedbackNode *feedback){
            cout<<"============================================================================================\n";
            cout<<"\t\t\t\tFeedbacks\n";  
            cout<<"============================================================================================\n\n";
            feedback->displayFeedback();
        }
    
};

#endif