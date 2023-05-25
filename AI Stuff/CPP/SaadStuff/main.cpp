#include<iostream>
#include<string>
#include"University.h"
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

using namespace std;


void LoadData()
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
       cout<<rank<<" "<<institute<<" "<<locationCode<<" "<<location<<" "<<arScore<<" "<<arRank<<" "<<erScore<<" "<<erRank<<" "<<fsrScore<<" "<<fsrRank<<" "<<cpfScore<<" "<<cpfRank<<" "<<ifrScore<<" ";
       cout<<ifrRank<<" "<<isrScore<<" "<<isrRank<<" "<<irnScore<<" "<<irnRank<<" "<<gerScore<<" "<<gerRank<<" "<<scoreScaled<<endl;
    }
    
}
void displayUniversities(){
    cout<<"Hello World"<<endl;
}
int main(){

// Readng data from CSV File
LoadData();



}