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
    while (std::getline(fin,line))
    {

        if (counter ==9)
            break;
        stringstream ss(line);
        string rank;                        //Rank Of the University
        string institute;                   //Name of he University
        string locationCode;                //Location Code
        string location;                    //Location
        string arScore;
        string arRank;
        string erScore;
        string erRank;
        string fsrScore;
        string fsrRank;
        string cpfScore;
        string cpfRank;
        string ifrScore;
        string ifrRank;
        string isrScore;
        string isrRank;
        string irnScore;
        string irnRank;
        string gerScore;
        string gerRank;
        string scoreScaled;
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

int main(){

// Readng data from CSV File
LoadData();



}