//
//  Person.hpp
//  C++第一天
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
using namespace std;
/**
 * 人 基本的一些信息
 *
 *
 */
class Person
{
  friend ostream &operator<<(ostream &out,const Person &p);
    
public:
    Person(const char *name,int age,double salary);
    
public:
    //set get函数
    void SetAge(int newAge);
    void SetSalary(double newSalary);
    
    int getID()const;
    int getAge();
    double getSalary();
    
public:
   void print();
public:
    //big three
    ~Person();
    Person(const Person& p);
    Person& operator=(const Person & p);
public:
   char *getName();
protected:
    char *_name;
    int _age;
    double _salary;
    int _id;
    static int next_id;
    static int _totalPersons;
    
};

#endif /* Person_hpp */
