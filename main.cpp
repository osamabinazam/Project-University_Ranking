#include <iostream>
#include <string>


#include <fstream>
#include <sstream>
#include <iomanip>
#include "LinkedList.h"
#include "Feedback.h"
#include <chrono>
#include <ctime>
#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"
#include "ClearScreen.h"
#include"Users.h"
using namespace std;
// Check Wheather the given column is integer or not
bool isNumber(const std::string &variable)
{
    std::istringstream iss(variable);
    double value;
    return (iss >> value) && (iss.eof());
}

// Load Data From CSV file into LinkedList
void LoadData(LinkedList<University> *L )
{
    int counter = 0;
    std::ifstream fin("universities_ranking.csv");
    string line;
    bool flag = true; // Using this flag to skip the first Row
    while (std::getline(fin, line))
    {
        if (flag)
        {
            flag = false;
            continue;
        }
        // if (counter ==5)        break;
        stringstream ss(line);
        string rank;         // Rank Of the University
        string institute;    // Name of he University
        string locationCode; // Location Code
        string location;     // Location
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

        // // Reading data from file and spliting data into varaiable using ","
        getline(ss, rank, ',');
        getline(ss, institute, ',');
        getline(ss, locationCode, ',');
        if (locationCode.length() != 2)
        {
            institute.append(locationCode);
            getline(ss, locationCode, ',');
        }
        getline(ss, location, ',');

        getline(ss, arScore, ',');
        if (!(isNumber(arScore)))
        {
            location.append(arScore);
            getline(ss, arScore, ',');
        }
        if (!isNumber(arScore))
        {
            arScore = "0.0";
        }
        if (arScore == "")
        {
            arScore = "0.0";
        }
        getline(ss, arRank, ',');
        getline(ss, erScore, ',');
        if (!(isNumber(erScore)))
        {
            erScore = "0.0";
        }
        if (erScore == "")
        {
            erScore = "0.0";
        }
        getline(ss, erRank, ',');
        getline(ss, fsrScore, ',');
        if (fsrScore == "")
        {
            fsrScore = "0.0";
        }
        if (!isNumber(fsrScore))
        {
            fsrScore = "0.0";
        }
        getline(ss, fsrRank, ',');
        getline(ss, cpfScore, ',');
        getline(ss, cpfRank, ',');
        getline(ss, ifrScore, ',');
        getline(ss, ifrRank, ',');
        getline(ss, isrScore, ',');
        getline(ss, isrRank, ',');
        getline(ss, irnScore, ',');
        getline(ss, irnRank, ',');
        getline(ss, gerScore, ',');
        getline(ss, gerRank, ',');
        getline(ss, scoreScaled, ',');


        //    cout<<rank<<" "<<institute<<" "<<locationCode<<" "<<location<<" "<<arScore<<" "<<arRank<<" "<<erScore<<" "<<erRank<<" "<<fsrScore<<" "<<fsrRank<<" "<<cpfScore<<" "<<cpfRank<<" "<<ifrScore<<" ";
        //    cout<<ifrRank<<" "<<isrScore<<" "<<isrRank<<" "<<irnScore<<" "<<irnRank<<" "<<gerScore<<" "<<gerRank<<" "<<scoreScaled<<endl;
        University *u = new University(rank, institute, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, ifrRank, gerScore, gerRank, scoreScaled);
        L->insert(u);
//    counter++;
    }
}



/*
    -> Home panel
    -> Display Option to start
*/

char StartPanel(bool flag)
{
    clearScreen();
    char choice = -1;
    cout << "============================================================================================\n";
    cout << "\t\t\t Welcome to the Universities Ranking System\n";
    cout << "============================================================================================\n\n";

    if (flag)
    {
        cout << "\nInvalid Input!, Please check your input\n\n";
    }
    cout << "1. MoEH Administrator\n2. Customer\n3. Normal User\n4. Exit\nSelect an option: ";
    cin >> choice;

    return choice;
}


void printArray(University arr[], int length)
{
    cout << "============================================================================================\n";
    cout << "\t\t\t\tUniversities Information\n";
    cout << "============================================================================================\n\n";
    char c;
    bool flag = false;
    int count = 1;
    for (int i = 0; i < length; i++)
    {
        flag = false;
        arr[i].toString();
        if (count == 50)
        {
            arr[i].toString();
            count = 1;
            cout << "1. More Universities\nPress any Key to \"Go Back\"\nEnter Your Choice : ";
            cin >> c;
            if (c == '1')
                continue;
            else
                break;
        }
        count++;
    }
}

// Calculate Current Date and Time and return as String
string getCurrentDate()
{
    // Get the current system time
    auto currentTime = chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Convert the system time to a calendar time
    tm *calendarTime = std::localtime(&currentTime);

    // Extract the year, month, and day from the calendar time
    int year = calendarTime->tm_year + 1900;
    int month = calendarTime->tm_mon + 1;
    int day = calendarTime->tm_mday;

    // Create a string representing the current date
    string currentDate = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);

    return currentDate;
}


/*
    -> Render user creation form
    -> Part of Normal User Panel
    -> Also add user to list
*/
User *CreateUserInterface()
{
    bool flag = false;
    cout << "============================================================================================\n";
    cout << "\t\t\t\tSign Up\n";
    cout << "============================================================================================\n\n";
    do
    {
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
        bool checkUser = false;
        bool isAdmin;
        cin.ignore();
        cout << "User Creation Form\n---------------------------------------------------------------- \n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cin.ignore();
        cout << "Gender: ";
        getline(cin, gender);
        cout << "Email: ";
        getline(cin, email);
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        cout << "Phone Number: ";
        getline(cin, phone);
        cout << "Country: ";
        getline(cin, country);
        char validater = 'Y';
        cout << "Is Given Information is correct ? (Y/N) (y/n)";
        cin >> validater;
        if (validater == 'Y' || validater == 'y')
        {
            User *newNode = new User(name, age, gender, email, username, password, phone, country);
            // u->insert (newNode);
            return newNode;
        }
        else
        {
            cout << "Please Provide Correct information" << endl;
            flag = true;
        }
    } while (flag);
    return nullptr;
}


/*
    -> Normal Panel That Rander Normal User's Options
    -> Also Handle Correponding Actions

*/
void NormalUserPanel(LinkedList<University> *l, LinkedList<User> *u)
{

    char ch;
    bool flag = false;
    bool flag0 = false;
    bool flag1=false;
    do
    {
        clearScreen();
        cout << "============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
        cout << "=====================================================\n";
        cout << "\t\t\tNormal User" << endl;
        cout << "=====================================================\n";

        if (flag){
            cout << "Please Select Correct option from \"Menu\"\n";
            flag = false;
        }

        char choice = '0';
        cout << "1. Display All Universities\n2. Sort Alphabaticaly\n3. Search University Detail\n4. Register as a customer of EE\n5. Exit\n";
        cout << "Select an Option: ";
        cin >> choice;
        User *us = nullptr;
        string name;
        Node<University> *uni = nullptr;
        // University uni;
        University unies[l->size];
        University university ;
        char in='0';

        switch (choice)
        {
        // Disply
        case '1':
            clearScreen();
            l->Display(l);
            break;

        // Sorting
        case '2':
            clearScreen();
            flag=false;
            cout << "============================================================================================\n";
            cout << "\t\t\t\tSelect Sorting Option\n";
            cout << "============================================================================================\n\n";
            cout<<"1. Sort using \"Merge Sort\"\n2. Sort using \"Insertion Sort\"\nPress any key to Go Back \n\nSelect an Option: ";
            cin>>in;
            switch (in){
                case '1':
                    clearScreen();
                    l->listToArray(l, unies);
                    mergeSort(unies, 0, l->size - 1);
                    printArray(unies, l->size);
                    break;
                case '2':
                    clearScreen();
                    l->listToArray(l, unies);
                    insertionSort(unies, l->size);
                    printArray(unies, l->size);
                    break;
                case 3:
                    clearScreen();
                    break;
                default:
                    flag = true;
                    break;

            }
            break;
        // Search
        case '3':

            clearScreen();
            cout << "============================================================================================\n";
            cout << "\t\t\t\tSelect Searching Option\n";
            cout << "============================================================================================\n\n";
            
            flag = false;
            cout<<"1. Search using \"Binary Search\"\n2. Search using  \"LinearSearch\"\nPress any key to Go Back \n\nSelect an Option: ";
            cin>>in;
            switch (in){
                case '1':
                    clearScreen();
                    cin.ignore();
                    do {
                    l->listToArray(l, unies);
                    cout<<"Enter the University Name: ";
                    getline(cin, name);
                    university = binarySearch(unies, l->size, name);
                    if (university.institute == ""){
                        cout << "University Not Found" << endl;
                        flag1 = true;
                    }
                    }while(flag1);
                    university.toString();
                    break;
                case '2':
                    clearScreen();
                    cin.ignore();
                    do {
                        flag1=false;
                        cout << "Please enter university's name : ";
                        getline(cin, name);
                        uni = linearSearchNode(l,name);
                        if (uni->data->institute == ""){
                            cout<<"University not Found!, Please enter correct name."<<endl;
                            flag1=true;
                        }
                    }while(flag1);  

                    uni->data->toString();
                    break;
                case 3:
                    clearScreen();
                    break;
                default:
                    flag = true;
                    break;
            }
            break;
        // register
        case '4':
            clearScreen();
            us = CreateUserInterface();
            if (us != nullptr)
            {
                u->insert(us);
                cout << "Registered Successfully\n";
            }
            else
            {
                cout << "User Creation Failed\n";
            }
            break;
        case '5':
            clearScreen();
            return;
        default:
            flag = true;
            break;
        }
        if (!flag){
            cout << "\nDo you want to perform another operation ? (Y/N)\n\n";
            cin >> ch;
        }
        else 
            ch='Y';
        clearScreen();
    } while (ch == 'Y' || ch == 'y');
}

// Feeback
Feedback* FeedBackForm(Node<User> *user, LinkedList<University> *universities)
{

    cout << "============================================================================================\n";
    cout << "\t\t\t\tCreate Your Feedback\n";
    cout << "============================================================================================\n\n";
    string feedback, uni_name, ftitle;
    Node<University> *uni = nullptr;
    cin.ignore();
    bool flag = false;
    do
    {
        flag = false;
        cout << "University name: ";
        getline(cin, uni_name);
        uni = linearSearchNode(universities, uni_name);
        if (uni->data == nullptr)
        {
            cout << "University not found!. Please enter correct University name" << endl;
            flag = true;
        }
    } while (flag);
    cout << "Feedback Title: ";
    getline(cin, ftitle);

    cout << "Enter feedback for further information about the university : ";
    getline(cin, feedback);
    string time = getCurrentDate();
    Feedback *f = new Feedback(*(user->data), feedback, *(uni->data), ftitle, time);
    return f;
}

// Customer Dashboard
void CustomerDashboard(LinkedList<University> *universities, LinkedList<User> *users, FeedbackList *feedback, Node<User> *user)
{
    char ch;
    bool flag = false, flag1=false, flag2=false, flag3=false;
    clearScreen();
    do
    {
        cout << "============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
        cout << "=====================================================\n";
        cout << "\t\tRegistered User" << endl;
        cout << "=====================================================\n";
        if (flag1){
            cout << "\nPlease Select Correct option from \"Menu\"\n\n";
            flag1 = false;
        }
        flag = false;
        char choice = '0';
        cout << "1. View Universities Information\n2. Feedback\n3. Favorites \n4. Logout\n";
        cout << "Select an Option: ";
        cin >> choice;
        User *us = nullptr;
        string name;
        Node<University> *uni = nullptr;
        Feedback *f;
        University uniArray[universities->size];
        universities->listToArray(universities, uniArray);
        string uni_name;
        string recoment_uni_name;

        string fd;
        switch (choice)
        {
        // Display Universities information
        case '1':
            clearScreen();
            cout << "============================================================================================\n";
            cout << "\t\t\t\tView Universities Information\n";
            cout << "============================================================================================\n\n";
            cout << "1. Sort Infotmation\n2. Search University \nPress any other key to Go Back\n";
            cout << "Select an Option: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
                clearScreen();
                cout << "============================================================================================\n";
                cout << "\t\t\t\tSort\n";
                cout << "============================================================================================\n\n";
                cout << "1. Sort by Academic Reputation Score \n2. Sort by Employer Reputation Score \n3. Sort by Student/Faculty Ratio\n4. Press any key to Go Back \nSelect an Option: ";
                cin >> choice;
                switch (choice)
                {
                case '1':
                    clearScreen();
                    cout << "============================================================================================\n";
                    cout << "\t\t\t\tBy Academic Reputation Score\n";
                    cout << "============================================================================================\n\n";
                    universities->sortDescending(uniArray, "ar_score", universities->size);
                    printArray(uniArray, universities->size);
                    break;
                case '2':
                    clearScreen();
                    cout << "============================================================================================\n";
                    cout<< "\t\t\t\tBy Employer Reputation Score\n";
                    cout << "============================================================================================\n\n";
                    universities->sortDescending(uniArray, "er_score", universities->size);
                    printArray(uniArray, universities->size);
                    break;
                case '3':
                    clearScreen();
                    cout << "============================================================================================\n";
                    cout << "\t\t\t\tBy Student to Teacher Ratio\n";
                    cout << "============================================================================================\n\n";
                    universities->sortDescending(uniArray, "fsr_score", universities->size);
                    printArray(uniArray, universities->size);
                    break;
                default:
                    flag = true;
                    break;
                }
                break;
            // Search 
            case '2':
                clearScreen();
                cin.ignore();
                cout << "============================================================================================\n";
                cout << "\t\t\t\tSearch\n";
                cout << "============================================================================================\n\n";
                do {
                    flag1=false;
                    cout << "Please enter university's name : ";
                    getline(cin, name);
                    uni = linearSearchNode(universities, name);
                    if (uni->data == nullptr)
                    {
                        cout << "University Not Found\n";
                        flag1 =true;
                        continue;
                    }
                    uni->data->toString();
                }while (flag1);
                break;
            default:
                flag = true;
                break;

            }
            break;
        //Add Feedback
        case '2':
            clearScreen();
                cout << "============================================================================================\n";
                cout << "\t\t\t\tFeedback\n";
                cout << "============================================================================================\n\n";
            cout << "1. Feedback To University\n2. See Feedback Reply(ies)\nPress any other key to Go Back\nSelect an option : ";
            cin >> choice;
            switch (choice)
            {
            case '1':
                clearScreen();
                f = FeedBackForm(user, universities);
                // Adding Feedback to FeedbackList
                feedback->insert(f);
                break;
            case '2':
                feedback->displayFeedbackReply(user->data);
                
                break;
            default:
                flag=true;
                break;
            }
            
            break;
        // Add University to favorite list
        case '3':
            
            do{
                clearScreen();
                cin.ignore();
                flag2=false;
                cout << "============================================================================================\n";
                cout << "\t\t\t\tFavorite Universities\n";
                cout << "============================================================================================\n\n";
                cout << "1. Add to favorites list\n2. List favorites\nPress any key to Go Back\n";
                cin >> choice;
                do {
                    flag1=false;
                    switch (choice)
                    {
                    case '1':
                        clearScreen();
                        cout << "============================================================================================\n";
                        cout << "\t\t\t\tAdd to Favorite\n";
                        cout << "============================================================================================\n\n";
                        cin.ignore();
                        do {
                            cout << "Enter University Name: ";
                            getline(cin, uni_name);
                            uni = linearSearchNode(universities,uni_name); 
                            if (uni->data->institute == "")
                            {
                                cout << "University Not Found\n";
                                flag1=true;

                            }
                            else
                            {
                                uni->data->recommend++;
                                user->data->favUnies.insert(uni->data);
                                cout << "Successfully added to favorite list" << endl;
                                cout<<"\nDo you want to add another to favorite list ? : (Y/N) or (y/n) :";
                                cin>>choice;
                                cin.ignore();
                                if(choice=='y'||choice=='Y')    flag2=true;
                                else {
                                    flag1=false;
                                    flag2=false;
                                    break;
                                } 
                            }
                        } while (flag1);
                        break;
                    case '2':
                        clearScreen();
                        cout << "============================================================================================\n";
                        cout << "\t\t\t\tFavorite Universites\n";
                        cout << "============================================================================================\n\n";
                        user->data->displayFavUnives((user->data->favUnies));
                        break;
                    default:
                        // flag2=true;
                        flag=true;
                        break;
                    }
                } while (flag1);
            }while(flag2);
            break;
        // Log out
        case '4':
            clearScreen();
            cout << "Logging out " << endl;
            return;
            break;
        default:
            flag1=true;
            break;
        }
        if (!flag){
            cout << "Do you want to perform another operation ? (Y/N)";
            cin >> ch;
        }
        else 
            ch ='Y';
        clearScreen();

    } while (ch == 'Y' || ch == 'y');
}






bool UpdateUser(Node<User> *user)
{
    cin.ignore();
    clearScreen();
    cout << "============================================================================================\n";
    cout << "\t\t\t\tUpdate User\n";
    cout << "============================================================================================\n\n";

    bool flag = false;
    do
    {
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
        bool checkUser = false;
        bool isAdmin;
        cout << "User Modification Form\n---------------------------------------------------------------- \n";
        cout << "Name: ";
        getline(cin, name);
        if (name.empty())
        {
            name = user->data->name;
        }
        cout << "Age: ";
        cin >> age;
        cin.ignore();
        cout << "Gender: ";
        getline(cin, gender);
        if (gender.empty())
        {
            gender = user->data->gender;
        }
        cout << "Email: ";
        getline(cin, email);
        if (email.empty())
        {
            email = user->data->email;
        }
        cout << "Username: ";
        getline(cin, username);
        if (username.empty())
        {
            username = user->data->username;
        }
        cout << "Phone Number: ";
        getline(cin, phone);
        if (phone.empty())
        {
            phone = user->data->phone;
        }
        cout << "Country: ";
        getline(cin, country);
        if (country.empty())
        {
            country = user->data->country;
        }
        char validater = 'Y';
        cout << "Is Given Information is correct ? (Y/N) (y/n)";
        cin >> validater;
        if (validater == 'Y' || validater == 'y')
        {

            user->data->name = name;
            user->data->email = email;
            user->data->country = country;
            user->data->gender = gender;
            user->data->phone = phone;
            user->data->isAdmin = isAdmin;
            user->data->age = age;
            user->data->username = username;
            // u->insert (newNode);
            return true;
        }
        else
        {
            cout << "Please Provide Correct information" << endl;
            flag = true;
        }
    } while (flag);
    return false;
}

// Admin Dashboard
void AdminDashboard(LinkedList<User> *U, FeedbackList *feedbacks, LinkedList<University>* Unies)
{
    char ch;
    bool flag = true;
    do
    {
        clearScreen();
        cout << "============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
        cout << "=====================================================\n";
        cout << "\t\tAdmin" << endl;
        cout << "=====================================================\n";

        int choice = -1;
        cout << "1. Display All Users\n2. Modify User\n3. Delete User\n4. Reply to Feedback\n5. Top 10 University recommended by parents\n6. Exit\n";
        cout << "Select an Option: ";
        cin >> choice;

        User *us = nullptr;
        Node<University> *uni = nullptr;
        Node<User> *userToSearch;
        string username = "";
        string reply;
        University topUnies[10];


        switch (choice)
        {
        case 1:
            clearScreen();
            cout << "============================================================================================\n";
            cout << "\t\t\t\tUsers\n";
            cout << "============================================================================================\n\n";

            U->Display(U);
            break;
        case 2:
            clearScreen();
            cin.ignore();
            cout << "============================================================================================\n";
            cout << "\t\t\t\tModify User\n";
            cout << "============================================================================================\n\n";

            cout << "Enter Username:";
            getline(cin, username);

            userToSearch = SearchUser(U, username);
            if (userToSearch != nullptr)
            {
                if (UpdateUser(userToSearch))
                {
                    cout << "User Updated Sucessfully!" << endl;
                }
                else
                {
                    cout << "Something went wrong" << endl;
                }
            }
            else
            {
                cout << "User does not exist" << endl;
            }

            break;
        case 3:
            clearScreen();
            cout << "============================================================================================\n";
            cout << "\t\t\t\tDelete User\n";
            cout << "============================================================================================\n\n";
            cin.ignore();
            cout << "Enter Username : ";
            getline(cin, username);
            userToSearch = SearchUser(U, username);

            if (userToSearch == nullptr)
            {
                cout << "User does not exist" << endl;
            }
            else if (U->deleteNode(userToSearch))
            {
                cout << "Sucessfully Deleted : " << endl;
            }
            break;
        case 4:
            clearScreen();
            if (!feedbacks->isEmpty())
            {
                FeedbackNode *currnet = feedbacks->tail;
                while (currnet != nullptr)
                {
                    feedbacks->displayFeedback(currnet);
                    cout << "1. Next Feeback\n2. Previous Feeback\n3. Reply to Feedback\n4. Back\nSelect an option :";
                    cin >> choice;
                    if (choice == 2 && currnet->next != nullptr)
                    {
                        currnet = currnet->next;
                        continue;
                    }
                    else if (choice == 1 && currnet->prev != nullptr)
                    {
                        currnet = currnet->prev;
                        continue;
                    }
                    else if (choice == 3)
                    {
                        cout << "Enter Your Feedback : ";
                        cin.ignore();
                        getline(cin, reply);
                        currnet->data.reply = reply;
                    }
                    else if (choice == 4)
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "============================================================================================\n";
                cout << "\t\t\t\tFeedbacks\n";
                cout << "============================================================================================\n\n";
                cout << "No Feedback Yet" << endl;
            }
            break;

        case 5:
            clearScreen();
            cout << "============================================================================================\n";
            cout << "\t\t\t\tTop 10 University Recommended by Parents\n";
            cout << "============================================================================================\n\n";
            Unies->recommendedUniversityies(Unies, topUnies);
            for (int i = 0; i < 10; i++){
                topUnies[i].toString();
            }
            break;
        case 6:
            flag = false;
            cout << "Exiting..." << endl;
            return;
        default:
            break;
        }
        cout << "Go Back ? (y/n)(Y/N) : ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            clearScreen();
            // break;
        }
        clearScreen();

    } while (flag);
}

User *LoginPanel(LinkedList<User> *U, LinkedList<University> *L, FeedbackList *F)
{
    cin.ignore();
    cout << "============================================================================================\n";
    cout << "\t\t\t Login to System\n";
    cout << "============================================================================================\n\n";
    string username = "";
    string password = "";
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    Node<User> *user = SearchUser(U,username);
    if (user == nullptr)
    {
        cout << "User does not exist. Try again" << endl;
        clearScreen();
        return nullptr;
    }
    if (username == "admin" && password == user->data->password && user->data->isAdmin == true)
    {
        AdminDashboard(U, F, L);
        return nullptr;
    }
    else if (username == user->data->username && password == user->data->password)
    {
        CustomerDashboard(L, U, F, user);
        return nullptr;
    }
    else
    {
        cout << "User Not Found!\n Please Check For Username and password and Try again" << endl;
        return nullptr;
    }
}

// Main Driven method

int main()
{
    LinkedList<University> *L = new LinkedList<University>();
    LinkedList<User> *U = new LinkedList<User>();
    // Dummy User
    User *usr = new User("John", 18, "male", "user@gmail.com", "user", "user", "093223", "Oman");
    U->insert(usr);
    FeedbackList *F = new FeedbackList();
    User *admin = new User("John", 18, "male", "admin@gmail.com", "admin", "admin", "093223", "Canada");
    admin->isAdmin = true;
    U->insert(admin);
    LoadData(L);
    University uni[L->size];
    L->listToArray(L, uni);

   
    bool flag = false;
    do
    {
        char choice = StartPanel(flag);
        flag = false;
        char ch;
        switch (choice)
        {
        case '1':
            clearScreen();
            LoginPanel(U, L, F);
            break;
        case '2':
            clearScreen();
            LoginPanel(U, L, F);
            break;
        case '3':
            clearScreen();
            NormalUserPanel(L, U);
            break;
        case '4':
            cout << "Thank you for using our platform" << endl;
            cout << "Exiting..." << endl;
            return 0;
        default:
            clearScreen();
            flag = true;
            break;
        }

    } while (true);
}