#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

#include <iostream>
#include<string>
using namespace std;

class User{
    public:
        string name;
        int age;
        int index;
        string gender;
        string email;
        string username;
        string password;
        string phone;
        string country;
        bool isAdmin;
        LinkedList<University> favUnies;

        User(){
            name = "";
            age = 0;
            gender = "";
            email = "";
            password = "";
            phone = "";
            country = "";
            isAdmin = false;
            index=0;
        }
        // Constructor
        User(string name, int age, string gender, string email,string username, string password, string phone, string country){
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->email = email;
            this->username= username;
            this->password = password;
            this->phone = phone;
            this->country = country;
            index = 0;

        }
        void displayFavUnives(LinkedList<University>  U){
            if (U.isEmpty()){
                cout<<"Nothing here!"<<endl;
            }
            else {
                Node<University> *current = U.head;
                while (current !=nullptr)
                {
                    
                    cout<<"Name : "<<current->data->institute<<endl;
                    cout<<"Rank : "<<current->data->rank<<endl;
                    cout<<"Location : "<<current->data->location<<endl;
                    cout<<"\n---------------------------------------------------------------------------------------------\n";
                    current = current->next;

                }
                
            }
        }

        void toString(){


            cout<<"\n------------------------------------------------------------------------\n";
            cout<<"Name     : "<<this->name<<"\nAge     : "<<this->age<<"\nUsername :"<<this->username<<"\n";
            cout<<"Email    : "<<this->email<<"\nPhone  : "<<this->phone<<"\nGender : "<<this->gender;
            

            cout<<"\n------------------------------------------------------------------------\n";
        }



};
#endif