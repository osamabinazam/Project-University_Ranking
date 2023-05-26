#include <iostream>
#include <string>
using namespace std;
class University
{
  public:
    
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

        University(){
        
        }

         University(string rank, string institute, string locationCode, string location,
               string arScore, string arRank, string erScore, string erRank, string fsrScore,
               string fsrRank, string cpfScore, string cpfRank, string ifrScore, string ifrRank,
               string isrScore, string isrRank, string irnScore, string irnRank, string gerScore,
               string gerRank, string scoreScaled)
    {
        this->rank = rank;
        this->institute = institute;
        this->locationCode = locationCode;
        this->location = location;
        this->arScore = arScore;
        this->arRank = arRank;
        this->erScore = erScore;
        this->erRank = erRank;
        this->fsrScore = fsrScore;
        this->fsrRank = fsrRank;
        this->cpfScore = cpfScore;
        this->cpfRank = cpfRank;
        this->ifrScore = ifrScore;
        this->ifrRank = ifrRank;
        this->isrScore = isrScore;
        this->isrRank = isrRank;
        this->irnScore = irnScore;
        this->irnRank = irnRank;
        this->gerScore = gerScore;
        this->gerRank = gerRank;
        this->scoreScaled = scoreScaled;
    }

    void toString (){
        cout<<"------------------------------------------------------------------------\n";
        cout << "Rank: " << rank << endl;
        cout << "Institute: " << institute << endl;
        cout << "Location Code: " << locationCode << endl;
        cout << "Location: " << location << endl;
        cout << "Academic Reputation Score: " << arScore << endl;
        cout << "Academic Reputation Rank: " << arRank << endl;
        cout << "Employer Reputation Score: " << erScore << endl;
        cout << "Employer Reputation Rank: " << erRank << endl;
        cout << "FSR Score: " << fsrScore << endl;
        cout << "FSR Rank: " << fsrRank << endl;
        cout << "CPF Score: " << cpfScore << endl;
        cout << "CPF Rank: " << cpfRank << endl;
        cout<<"------------------------------------------------------------------------\n";
    }
        

};
