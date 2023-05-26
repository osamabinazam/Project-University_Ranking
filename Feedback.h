#include<iostream>
#include<string>
#include"Users.h"
class Feedback{
    public:
        User user;
        string feedback;

        Feedback(User user, string feedback){
            this->user = user;
            this->feedback = feedback;
        }
};