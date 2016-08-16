//
//  Candidate.hpp
//  C++第一天
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#ifndef Candidate_hpp
#define Candidate_hpp

#include <iostream>
using namespace std;
#include "Person.hpp"
#include "Voter.hpp"
class Voter;
class PersonSet;
class Candidate :public Person
{
   friend ostream & operator<<(ostream &out,Candidate &c);
   friend bool operator<(const Candidate &c1, const Candidate c2);

public:
    Candidate(const char *name,int age,double salary);
    void AddVoter(Voter &aVoter);
    
public:
    /*get函数*/
    double GetAverageVoterAge();
    double GetAverageVoterSalary();
    int    GetVotesNum();
    static int candidate();
    
protected:
    PersonSet  _voterSet;
    double average_age;
    double average_salary;
    static int _numCandidates;
};
#endif /* Candidate_hpp */
