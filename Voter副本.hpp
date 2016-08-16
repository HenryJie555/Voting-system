//
//  Voter.hpp
//  C++第一天
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#ifndef Voter_hpp
#define Voter_hpp
#include "Person.hpp"
#include "PersonSet.hpp"
#include "Candidate.hpp"
#include <iostream>
class Candidate;
using namespace std;

class Voter:public Person
{
   
    friend bool operator==(const Voter &v1,const Voter &v2);
public:
    
    Voter(const char *name,int age,double salary,int polingStation);
    
public:
    void SetPolingStation(int newPolingStation);
    Person& SelectCandidate(PersonSet& candidates);
    
public:
    const Voter& operator=(const Voter &v);
    static int Voters();
    void Vote(Candidate& aCandidate);//投票函数
    void Print();
    
private:
    int _polingStation;
    static int _totalNumVoters;
};

#endif /* Voter_hpp */
