//
//  Person.cpp
//  C++第一天
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#include "Person.hpp"

int Person::next_id=0;
int Person::_totalPersons=0;


Person::Person(const char *name,int age,double salary)
{
    next_id++;
    _id=next_id;
    _name=new char[strlen(name)+1];
    strcpy(_name, name);
    _age=age;
    _salary=salary;
}


void Person::SetAge(int newAge)
{
    _age=newAge;
}

void Person::SetSalary(double newSalary)
{
    _salary=newSalary;
}

int Person:: getAge()
{
    return _age;
}
double Person::  getSalary()
{
    return _salary;
}
int Person:: getID()const
{
    return _id;
}

char *Person::getName()
{
    return _name;
}

Person::~Person()
{
    delete []_name;
    _name=NULL;
}
Person::Person(const Person& p)
{
    _name=new char[strlen(p._name)+1];
    strcpy(_name, p._name);
    _age=p._age;
    _salary=p._salary;
}
Person& Person::operator=(const Person & p)
{
    if (this!=&p)
    {
        delete []_name;
        _name=new char[strlen(p._name)+1];
        strcpy(_name, p._name);
        _age=p._age;
        _salary=p._salary;
        
    }
    return *this;
}
void Person::print()
{
    cout<<*this<<endl;;
}

ostream &operator<<(ostream &out,const Person &p)
{
    
    out<<"ID:"<<p._id<<"\tName:"<<p._name<<"\tAge:"<<p._age<<"\tSalary:"<<p._salary;
    return out;
}


