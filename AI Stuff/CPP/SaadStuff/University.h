#include <iostream>
#include <string>

class University
{
  public:
    // string name;
    int academic_reputation;
    int employer_reputation;
    int faculty_student_ratio;
    int citations_per_faculty;
    int international_faculty_ratio;
    int international_student_ratio;
    int international_research_network;
    int employment_outcome;

    University(int academic_reputation, int employer_reputation, int faculty_student_ratio, int citations_per_faculty, int international_faculty_ratio, int international_student_ratio, int international_research_network, int employment_outcome);

};

University::University(int academic_reputation, int employer_reputation, int faculty_student_ratio, int citations_per_faculty, int international_faculty_ratio, int international_student_ratio, int international_research_network, int employment_outcome) {
    // this->name = name;
    this->academic_reputation = academic_reputation;
    this->employer_reputation = employer_reputation;
    this->faculty_student_ratio = faculty_student_ratio;
    this->citations_per_faculty = citations_per_faculty;
    this->international_faculty_ratio = international_faculty_ratio;
    this->international_student_ratio = international_student_ratio;
    this->international_research_network = international_research_network;
    this->employment_outcome = employment_outcome;
  }
