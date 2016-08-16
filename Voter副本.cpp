//
//  Voter.cpp
//  C++第一天
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#include "Voter.hpp"
#include "Person.hpp"

int Voter:: _totalNumVoters=0;

Voter::Voter(const char *name,int age,double salary,int polingStation):Person(name,age,salary)
{
    _polingStation=polingStation;
    _totalNumVoters++;
}

void Voter::SetPolingStation(int newPolingStation)
{
    _polingStation=newPolingStation;
}


void Voter::Print()
{
    cout<<"投票人: "<<_name<<"  ID: "<<_id<<endl;
}

const Voter& Voter::operator=(const Voter &v)
{
    if (this!= &v)
    {
        delete []_name;
        _name = new char[strlen(v._name)+1];
        strcpy(_name, v._name);
        _age=v._age;
        _salary=v._salary;
        _polingStation=v._polingStation;
    }
    return *this;
}

int Voter::Voters()
{
    return _totalNumVoters;
}

/*选择候选人 随机产生一个候选人*/
Person& Voter::SelectCandidate(PersonSet& candidates)
{
    
    int r = rand()%candidates.Size();
    Person* pCandidate = &candidates[r];
    return *pCandidate;
}

/*投票函数*/
void Voter::Vote(Candidate& aCandidate)
{
  aCandidate.AddVoter(*this);
}


bool operator==(const Voter &v1,const Voter &v2)
{
    if (v1.getID()==v2.getID())
    {
        return true;
    }else
        return false;
}
