#include<iostream>
#include<string>

#include <fstream>
#include <sstream>
#include <iomanip>
#include"LinkedList.h"
#include"Feedback.h"
// #include"Users.h"
using namespace std;

// Load Data
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
         if (arScore==""){
            arScore = "0.0";
        }
        getline(ss,arRank,',');
        getline(ss,erScore,',');
         if (erScore==""){
            erScore = "0.0";
        }
        getline(ss,erRank,',');
        getline(ss,fsrScore,',');
          if (fsrScore==""){
            fsrScore = "0.0";
        }
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
//Helper Method merge sort
void merge(University arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    University L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i].institute <= R[j].institute)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(University arr[], int left, int right)
{
    if (left < right)
    {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
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
        bool flag = false;
        do{
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
                flag= true;
            }
        }
        while (flag);
    
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
    University unies[l->size];
    l->listToArray(l,unies);
    switch (choice)
    {
    case 1:
        system("cls");
        l->Display(l);
        break;
    case 2:
        system("cls");
        cout<<"Worked"<<endl;
        mergeSort(unies, 0, l->size-1);
        break;
    case 3:
        system("cls");
        cin.ignore();
        cout<<"Please enter university's name : ";
        getline (cin,name);
        // uni=l->LinearSearchNode(name);
        
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




Feedback* FeedBackForm(Node<User>* user, LinkedList<University>* universities){
    string feedback, uni_name,ftitle;
    Node<University>* uni=nullptr;
    cin.ignore();
    bool flag = false;
    do {
    flag=false;
    cout<<"University name: ";
    getline (cin,uni_name);
    uni=universities->LinearSearchNode(uni_name);
        if (uni==nullptr){
            cout<<"University not found!. Please enter correct University name"<<endl;
            flag=true;
        }
    }while(flag);
    cout<<"Feedback Title: ";
    getline (cin,ftitle);

    cout<<"Enter feedback for further information about the university : ";
    getline(cin,feedback);
    cout<<"Testting 3"<<endl;
    Feedback *f = new Feedback(*(user->data),feedback, *(uni->data), ftitle);
    return f;

}


// Customer Dashboard
void CustomerDashboard(LinkedList<University>* universities , LinkedList<User>* users, FeedbackList* feedback, Node<User>* user){
    char ch;
    system("cls");
    do{
    cout<<"============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
    int choice=-1;
    cout<<"1. View Universities Information\n2. Feedback\n3. Add University to Favorite\n4. Logout\n";
    cout<<"Select an Option: ";
    cin>>choice;   
    User* us=nullptr;
    string name;
    Node<University>* uni=nullptr;
    Feedback *f;
    University uniArray[universities->size];
    universities->listToArray(universities, uniArray);
    string uni_name;

    
    string fd;
    switch (choice)
    {
    case 1:
        system("cls");
        cout<<"1. Sort Infotmation\n2. Search University \n3. Back\n";
        cout<<"Select an Option: ";
        cin>>choice;
        switch (choice){
            case 1:
                system("cls");
                cout<<"1. Sort by Academic Reputation Score \n2. Sort by Employer Reputation Score \n3. Sort by Student/Faculty Ratio\nSelect an Option: ";
                cin>>choice;
                switch(choice){
                    case 1:
                        system("cls");
                        universities->sortDescending(uniArray, "ar_score", universities->size);
                        break;
                    case 2:
                        system("cls");
                        universities->sortDescending(uniArray, "er_score", universities->size);
                        break;
                    case 3:
                        system("cls");
                        universities->sortDescending(uniArray, "fsr_score", universities->size);
                        break;
                    default:
                            break;
        
                }
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
            case 4:
                break;

        }
        break;
    case 2:
        system("cls");
        cout<<"1. Feedback To University\n2. See Feedback Reply(ies)\n3. Back\nSelect an option : ";
        cin>>choice;
        switch(choice){
            case 1:
                system("cls");
                f= FeedBackForm(user, universities);
                // Adding Feedback to FeedbackList
                feedback->insert(f);
                break;
            case 2:
                feedback->displayFeedbackReply(user->data);
                break;
            case 3:
                break;
        }
            
        break;
    case 3:
                cout<<"Enter University Name: ";
                cin>>uni_name;
                uni= universities->LinearSearchNode(uni_name);
                user->data->favUnies.insert(uni->data);
    case 4:
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


bool UpdateUser(Node<User>* user){
    
    bool flag =false;
    do{    
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
        cin.ignore();
        cout<<"User Modification Form\n---------------------------------------------------------------- \n";
        cout<<"Name: ";
        getline (cin, name);
        if (name.empty()){
            name=user->data->name;
        }
        cout<<"Age: ";
        cin>>age;
        cin.ignore ();
        cout<<"Gender: ";
        getline (cin, gender);
        if (gender.empty()){
            gender=user->data->gender;
        }
        cout<<"Email: ";
        getline (cin, email);
        if (email.empty()){
            email=user->data->email;
        }
        cout<<"Username: ";
        getline (cin, username);
        if (username.empty()){
            username=user->data->username;
        }
        cout<<"Phone Number: ";
        getline (cin, phone);
        if (phone.empty()){
            phone=user->data->phone;
        }
        cout<<"Country: ";
        getline (cin, country);
        if (country.empty()){
            country=user->data->country;
        }
        char validater = 'Y';
        cout<<"Is Given Information is correct ? (Y/N) (y/n)";
        cin>>validater;
        if(validater == 'Y' || validater == 'y'){

            user->data->name = name;
            user->data->email= email;
            user->data->country=country;
            user->data->gender=gender;
            user->data->phone=phone;
            user->data->isAdmin=isAdmin;
            user->data->age=age;
            user->data->username=username;
            // u->insert (newNode);
            return true;
            
        }
        else{
            cout<<"Please Provide Correct information"<<endl;
            flag =true;
            }    
    }while(flag);
    return false;
}

// Admin Dashboard
void AdminDashboard(LinkedList<User>* U, FeedbackList* feedbacks){
    char ch;
    bool fa;
    do{
    system("cls");
    cout<<"============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
    int choice=-1;
    cout<<"1. Display All Users\n2. Modify User\n3. Delete User\n4. Reply to Feedback\n5. Top 10 University recommended by parents\n6. Exit\n";
    cout<<"Select an Option: ";
    cin>>choice;   
    User* us=nullptr;
    Node<University>* uni=nullptr;
    Node <User>* userToSearch;
    string username="";
    switch (choice)
    {
    case 1:
        system("cls");
        U->Display(U);
        break;
    case 2:
        system("cls");
        cin.ignore();
        cout<<"Enter Username:";
        getline(cin, username);
        userToSearch = U->SearchUser(username);
        if (userToSearch != nullptr){
                if (UpdateUser(userToSearch)){
                cout<<"User Updated Sucessfully!"<<endl;
            }
            else {
                cout<<"Something went wrong"<<endl;
            }    
        }
        else {
            cout<<"User does not exist"<<endl;
        }
        
        break;
    case 3:
        system("cls");
        cin.ignore();
        cout<<"Enter Username : ";
        getline(cin,username);
        userToSearch=U->SearchUser(username);
        
        
        if(userToSearch==nullptr)
        {
            cout<<"User does not exist"<<endl;
        }
        else if(U->deleteNode(userToSearch)){
            cout<<"Sucessfully Deleted : "<<endl;
        }
        
        // cout<<"Delete User Implement later\n";
        break;
    case 4:
        
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




User* LoginPanel(LinkedList<User>* U , LinkedList<University>* L, FeedbackList* F){
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
    if(username == "admin" && password=="admin"){
        AdminDashboard(U, F);
        return nullptr;
    }
    else if (username == user->data->username && password == user->data->password){
        CustomerDashboard(L, U, F , user);
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
// Dummy User
User* usr = new User("John",18,"male", "osama@gmail.com", "osama", "toor","093223","Pakisan");
U->insert(usr);
FeedbackList * F = new FeedbackList();
User * admin = new User("John",18,"male", "osama@gmail.com", "admin", "admin","093223","Pakisan");
admin->isAdmin=true;
U->insert(admin);
LoadData(L);
Feedback *f = new Feedback(*(new User("John",18,"male", "osama@gmail.com", "admin", "admin","093223","Pakisan")), "Hello",*( L->LinearSearchNode("Harvard University")->data), "Testing Purpose");
F->insert(f);
cout<<"Size of Feedback list is : "<<F->size<<endl;
University uni[L->size];
L->listToArray(L, uni);

do{

    int choice = StartPanel();
    char ch ;
    switch (choice)
    {
    case 1:
        system("cls");
        LoginPanel(U,L,F);    
        break;
    case 2:
        system("cls");
        LoginPanel(U,L,F);
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