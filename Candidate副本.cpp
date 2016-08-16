//
//  Candidate.cpp
//  C++第一天
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#include "Candidate.hpp"
#include "Voter.hpp"
#include "Person.hpp"
#include "PersonSet.hpp"

int Candidate:: _numCandidates=0;

Candidate::Candidate(const char *name,int age,double salary):Person(name,age,salary)
{
_numCandidates++;
}

/*候选人票数*/
int Candidate:: GetVotesNum()
{
    int size=(_voterSet).Size();
    return size;
}

void Candidate:: AddVoter(Voter &aVoter)
{
    _voterSet.Add(aVoter);
}

double Candidate::GetAverageVoterAge()
{
    int sumAge=0;
    int sum=_voterSet.Size();
    
    for (int i=0; i<sum; i++)
    {
        sumAge+=_voterSet.NextElement().getAge();
        
    }
    average_age=sumAge/sum;
    return average_age;
}

double Candidate:: GetAverageVoterSalary()
{
    double sumSalary=0;
    int sum=_voterSet.Size();
    for (int i=0; i<sum; i++)
    {
        sumSalary+=_voterSet.NextElement().getSalary();
        average_salary=sumSalary/sum;
        
    }return average_salary;
}

int Candidate::candidate()
{
    return _numCandidates;
}

/*输出运算符重载*/
ostream & operator<<(ostream &out,Candidate &c)
{
   
    if (c.GetVotesNum()==0)
    {
        out<<"There are no voters!!!"<<endl;
    }else
    {
        out<<c.getName()<<endl;
    }
    return out;
}

bool operator<(const Candidate &c1, const Candidate c2)
{
    if (c1._voterSet.Size()>c2._voterSet.Size())
    {
        return false;
    }
    return true;
}