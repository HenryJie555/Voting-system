//
//  PersonSet.hpp
//  C++第一天
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#ifndef PersonSet_hpp
#define PersonSet_hpp

#include "Person.hpp"
#include <iostream>
using namespace std;
class PersonSet
{
    friend ostream& operator<<(ostream& out,const PersonSet& set);
public:
    PersonSet ();
//   ~PersonSet ();
public:
    void Add(Person & element) ;
    Person & NextElement();
public:
    
    Person & RemoveElement();
    Person & RemoveElement(int index);
    int Size()const;
    void print()const;
    void Reset();
    const Person & operator[](int index) const;
    Person &operator[](int index);
public:
    /*get函数*/
    Person& getElements(int r);
    int getIndex();
private:
    Person ** _elements;
    int _capacity;
    int _size;
    int _index;
};

#endif /* PersonSet_hpp */
