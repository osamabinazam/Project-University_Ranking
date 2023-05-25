#include<iostream>
#include<string>

#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <climits>
#include"LinkedList.h"

using namespace std;


void LoadData(LinkedList* L )
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
       L->insert(new University(rank, institute, locationCode, location,arScore,arRank, erScore,erRank,fsrScore,fsrRank,cpfScore,cpfRank,ifrScore,ifrRank, isrScore,isrRank,irnScore,ifrRank, gerScore, gerRank, scoreScaled));
    //    counter++;
    }
    
}
void displayUniversities(){
    cout<<"Hello World"<<endl;
}
void DisplayMenu(){
    cout<<"============================================================================================\n\tTOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n============================================================================================\n";
    cout<<"1. Display All Universities\n2. Sort Alphabaticaly\n3. Search University Detail\n4. Register as a customer of EE\n";
}
int main(){
LinkedList* L = new LinkedList();
LoadData(L);
DisplayMenu();
int choice=-1;
cout<<"Enter Your Choice: ";
cin>>choice;
if (choice ==1 ){
    cout<<"The Size of List is : "<<L->size<<"\nUniversities are : \n";
    // L->printUniversities();
}


// Readng data from CSV File

// LoadData();



}