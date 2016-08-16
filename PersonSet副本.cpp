//
//  PersonSet.cpp
//  C++第一天
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#include "PersonSet.hpp"
#include "Person.hpp"


PersonSet::PersonSet()
{
    int initial_size=4;
    _capacity=initial_size;
    _size=0;
    _index=0;
    _elements = new Person*[_capacity];
}

//PersonSet::~PersonSet()
//{
//    delete []_elements;
//    _elements = NULL;
//}

void PersonSet::Add( Person& aPerson )
{
    // Relocate the array space
    if ( _size == _capacity ) {
        Person** temp = _elements;
        _elements = new Person*[_capacity*2];
        for( int i=0; i<_size; i++ )
        {
            _elements [i] = temp[i];
        }
        _capacity*= 2;
//        cout<<"扩容后 当前容量大小: "<<_capacity<<endl;
        
        delete [] temp;
    }
    _elements[_size++] = &aPerson;
    
}

//从set中移除最后一个成员
//如果Set空的数据超过一半，释放一些内存；
Person & PersonSet::RemoveElement()
{
    _size--;
    Person* p=_elements[_size]; //shrink the container
    if(_size < _capacity/2) {
//        cout<<"释放内存 当前容量大小: "<<_capacity<<endl;
        
        Person** temp = _elements;
        _elements= new Person *[_capacity/2];
        for ( int i=0; i<_size; i++ )
        {
            _elements [i] = temp[i];
        }
        _capacity /= 2;
        delete [] temp;
    }
    return *p;
}
//从Set中的index索引处移除成员
//如果Set空的数据超过一半，释放一些内存

Person & PersonSet::RemoveElement(int index)
{
    Person* p=_elements[index];
    //shrink the container
    if(_size < _capacity/2)
    {
        
        Person** temp = _elements;
        _elements= new Person *[_capacity/2];
        for ( int i=0; i<_size; i++ )
        {
            _elements [i] = temp[i];
        }
        
        _capacity /= 2;
        delete [] temp;
    }
    
    for ( int i=index; i<_size; i++ )
    {
        _elements[i] = _elements[i+1];
    }
    _size--;
    return *p;
}


Person & PersonSet::NextElement()//递归
{
    _index = _index%_size;
    return *_elements[_index++];
}

void PersonSet::print()const//打印函数  打出所有的元素
{
    for(int i=0;i<_size;i++)
        ( *_elements[i]).print();
}

int PersonSet::Size() const
{
    return _size;
}

Person& PersonSet:: getElements(int r)
{
    return *_elements[r];
}
void PersonSet::Reset()//重置函数  做清零操作
{
    _index=0;
}
int PersonSet::getIndex()
{
    return _index;
}

const Person & PersonSet::operator[](int index) const
{
    return **(_elements+index);
}

 Person& PersonSet:: operator[](int index)
{
    return **(_elements+index);
}

