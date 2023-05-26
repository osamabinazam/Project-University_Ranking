#include<iostream>
#include<string>

#include <fstream>
#include <sstream>
#include <iomanip>
#include"LinkedList.h"
#include"Users.h"
using namespace std;


void LoadData(LinkedList<University>* L )
{
    int counter =0;
    std::ifstream fin("universities_ranking.csv");
    string line;
    bool flag = true;                       //Using this flag to skip the first Row
    while (std::getline(fin,line))
    {
        if(flag){
            flag = false;
            continue;
        }
        // if (counter ==5)        break;
        stringstream ss(line);
        string rank;                        //Rank Of the University
        string institute;                   //Name of he University
        string locationCode;                //Location Code
        string location;                    //Location
        // Academic Reputation
        string arScore;
        string arRank;
        // Employer Reputation
        string erScore;
        string erRank;
        // faculty/student ratio
        string fsrScore;
        string fsrRank;
        // (citations per faculty
        string cpfScore;
        string cpfRank;
        // international faculty ratio
        string ifrScore;
        string ifrRank;
        // international student ratio
        string isrScore;
        string isrRank;
        // international research network
        string irnScore;
        string irnRank;
        // employment outcome
        string gerScore;
        string gerRank;
        // Scalled
        string scoreScaled;

        // Reading data from file and spliting data into varaiable using "," 
        getline(ss,rank,',');
        getline(ss,institute,',');
        getline(ss,locationCode,',');
        getline(ss,location,',');
        getline(ss,arScore,',');
        getline(ss,arRank,',');
        getline(ss,erScore,',');
        getline(ss,erRank,',');
        getline(ss,fsrScore,',');
        getline(ss,fsrRank,',');
        getline(ss,cpfScore,',');
        getline(ss,cpfRank,',');
        getline(ss,ifrScore,',');
        getline(ss,ifrRank,',');
        getline(ss,isrScore,',');
        getline(ss,isrRank,',');
        getline(ss,irnScore,',');
        getline(ss,irnRank,',');
        getline(ss,gerScore,',');
        getline(ss,gerRank,',');
        getline(ss,scoreScaled,',');
    //    cout<<rank<<" "<<institute<<" "<<locationCode<<" "<<location<<" "<<arScore<<" "<<arRank<<" "<<erScore<<" "<<erRank<<" "<<fsrScore<<" "<<fsrRank<<" "<<cpfScore<<" "<<cpfRank<<" "<<ifrScore<<" ";
    //    cout<<ifrRank<<" "<<isrScore<<" "<<isrRank<<" "<<irnScore<<" "<<irnRank<<" "<<gerScore<<" "<<gerRank<<" "<<scoreScaled<<endl;
       University* u = new University(rank, institute, locationCode, location,arScore,arRank, erScore,erRank,fsrScore,fsrRank,cpfScore,cpfRank,ifrScore,ifrRank, isrScore,isrRank,irnScore,ifrRank, gerScore, gerRank, scoreScaled);
       L->insert(u);
    //    counter++;
    }
    
}
void displayUniversities(){
    cout<<"Hello World"<<endl;
}


// Starting Panel
int StartPanel(){
    int choice=-1;
    cout<<"------------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t Welcome to the Universities Ranking System\n";
    cout<<"------------------------------------------------------------------------------------------\n";
    cout<<"1. MoEH Administrator\n2. Customer\n3. Normal User\n4 Exit\n";
    cin>>choice;
    return choice;
}

// Create User Interface
User* CreateUserInterface(){
        bool flag = true;
        string name;
        int age;
        string gender;
        string email;
        string password;
        string phone;
        string address;
        string city;
        string country;
        string username;
        bool checkUser=false;
        bool isAdmin;
        cout<<"User Creation Form\n---------------------------------------------------------------- \n";
        cout<<"Name: ";
        cin>>name;
        cout<<"Age: ";
        cin>>age;
        cout<<"Gender: ";
        cin>>gender;
        cout<<"Email: ";
        cin>>email;
        cout<<"Username: ";
        cin>>username;        
        cout<<"Password: ";
        cin>>password;
        cout<<"Phone Number: ";
        cin>>phone;
        cout<<"Country: ";
        cin>>country;
        char validater = 'Y';
        cout<<"Is Given Information is correct ? (Y/N) (y/n)";
        cin>>validater;
        if(validater == 'Y' || validater == 'y'){
            User* newNode = new User (name, age, gender, email,username, password, phone,country);
            // u->insert (newNode);
            return newNode;
            
        }
        else{
            cout<<"Please Provide Correct information"<<endl;
        }
        return nullptr;
    
}



void NormalUserPanel(LinkedList<University> *l, LinkedList<User> *u){
    
    char ch;
    do{
    cout<<"============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
    int choice=-1;
    cout<<"1. Display All Universities\n2. Sort Alphabaticaly\n3. Search University Detail\n4. Register as a customer of EE\n5. Exit\n";
    cout<<"Select an Option: ";
    cin>>choice;   
    User* us=nullptr;
    string name;
    Node<University>* uni=nullptr;
    switch (choice)
    {
    case 1:
        system("cls");
        l->Display(l);
        break;
    case 2:
        system("cls");
        cout<<"Will be Implemented\n";
        break;
    case 3:
        system("cls");
        cin.ignore();
        cout<<"Please enter university's name : ";
        getline (cin,name);
        uni=l->LinearSearchNode(name);
        uni->data->toString();
        break;
    case 4:
        system("cls");
        us = CreateUserInterface();
        if (us != nullptr ){
            u->insert(us);
            cout<<"Registered Successfully\n";
        }
        else {
            cout<<"User Creation Failed\n";
        }
        break;
    case 5:
        return;
    default:
        break;
    }
    cout<<"Do you want to perform another operation ? (Y/N)";
    cin>>ch;
    system("cls");
    }while(ch == 'Y' || ch == 'y');

}


// Customer Dashboard
void CustomerDashboard(LinkedList<University>* universities , LinkedList<User>* users){
    char ch;
    do{
    cout<<"============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
    int choice=-1;
    cout<<"1. View Universities Information\n2. Feedback\n3. Logout\n";
    cout<<"Select an Option: ";
    cin>>choice;   
    User* us=nullptr;
    string name;
    Node<University>* uni=nullptr;
    switch (choice)
    {
    case 1:
        system("cls");
        cout<<"1. Sort Infotmation By Name \n2. Search University \n3. Back\n";
        cout<<"Select an Option: ";
        cin>>choice;
        switch (choice){
            case 1:
                universities->Display(universities);
                break;
            case 2:
                system("cls");
                cin.ignore();
                cout<<"Please enter university's name : ";
                getline (cin,name);
                uni=universities->LinearSearchNode(name);
                if (uni==nullptr) {
                    cout<<"University Not Found\n";
                    continue;
                }
                uni->data->toString();
                break;
            case 3:
                break;

        }
        break;
    case 2:
        system("cls");
        cout<<"Feedback System  Implement later\n";
        break;
    case 3:
        system("cls");
        cout<<"Logging out "<<endl;
        return;
        break;
    default:
        return;
        break;
    }
    cout<<"Do you want to perform another operation ? (Y/N)";
    cin>>ch;
    system("cls");

    }while(ch == 'Y' || ch == 'y');
}

// Admin Dashboard
void AdminDashboard(LinkedList<User>* U){
    char ch;
    do{
    system("cls");
    cout<<"============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
    int choice=-1;
    cout<<"1. Display All Users\n2. Modify User\n3. Delete User\n4. Reply to Feedback\n5. Top 10 University recommended by parents\n6. Exit\n";
    cout<<"Select an Option: ";
    cin>>choice;   
    User* us=nullptr;
    Node<University>* uni=nullptr;
    switch (choice)
    {
    case 1:
        system("cls");
        U->Display(U);
        break;
    case 2:
        system("cls");
        cout<<"Modify User Implement later\n";
        break;
    case 3:
        system("cls");
        // uni=UL->LinearSearchNode("Stanford University");
        cout<<"Delete User Implement later\n";
        break;
    case 4:
        cout<<"Implement it Later"<<endl;
        break;
    case 6:
        cout<<"Exiting..."<<endl;
        return;
    default:
        break;
    }
    cout<<"Do you want to perform another operation ? (Y/N)";
    cin>>ch;
    system("cls");

    }while(ch == 'Y' || ch == 'y');
}




User* LoginPanel(LinkedList<User>* U ){
    cin.ignore();
    cout<<"------------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t Login to System\n";
    cout<<"------------------------------------------------------------------------------------------\n";
    string username="";
    string password="";
    cout<<"Enter Username: ";
    getline(cin,username);
    cout<<"Enter Password: ";
    getline(cin,password);
    Node<User>* user = U->SearchUser(username);

    if(username == "admin" && user->data->password==password){
        AdminDashboard(U);
        return nullptr;
    }
    else if (username == "osama" && password =="toor"){
        cout<<"Logged in as osama"<<endl;
        return nullptr;
    }
    else{
        cout<<"User Not Found!\n Please Check For Username and password and Try again"<<endl;
        return nullptr;
    }

}


// Main Driven method

int main(){
LinkedList<University>* L = new LinkedList<University>();
LinkedList<User>* U = new LinkedList<User>();
U->insert(new User("John",18,"male", "osama@gmail.com", "admin", "admin","093223","Pakisan"));
LoadData(L);
University uni[L->size];
L->listToArray(L, uni);


do{

    int choice = StartPanel();
    char ch ;
    switch (choice)
    {
    case 1:
        system("cls");
        LoginPanel(U);    
        break;
    case 2:
        system("cls");
        CustomerDashboard(L, U);
        cout<<"Will Be implemented\n";    
        break;
    case 3:
        system("cls");
        NormalUserPanel(L, U);
        break;
    case 4:
        cout<<"Thank you for using our platform"<<endl;
        cout<<"Exiting..."<<endl;
        return 0;
    default:
        break;
    }

}while (true);





// Readng data from CSV File

// LoadData();



}