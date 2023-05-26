#include <iostream>
#include<string>
using namespace std;

class User{
    public:
        string name;
        int age;
        string gender;
        string email;
        string username;
        string password;
        string phone;
        string country;
        bool isAdmin;

        User(){
            name = "";
            age = 0;
            gender = "";
            email = "";
            password = "";
            phone = "";
            country = "";
            isAdmin = false;
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
        }

        void toString(){


            cout<<"------------------------------------------------------------------------\n";
            cout<<"Name: "<<this->name<<"\nAge : "<<this->age<<endl;
            cout<<"Email: "<<this->email<<"\nPhone: "<<this->phone<<"\nGender: "<<this->gender;

            cout<<"------------------------------------------------------------------------\n";
        }



};