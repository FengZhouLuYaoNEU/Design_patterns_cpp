#ifndef OBSERVER_BASE_H_
#define OBSERVER_BASE_H_

#include <iostream>
class ObserverBase
{
public:
    virtual void update(int data) = 0;
    virtual ~ObserverBase(){}
};
class FirstObserver : public ObserverBase
{
public:
    void update(int data)
    {
        std::cout<<"I am the FirstObserver and data is "<<data<<std::endl;
    }
    ~FirstObserver()
    {
        std::cout<<" FirstObserver destroyed "<<std::endl;
    }
};
class SecondObserver : public ObserverBase
{
public:
    void update(int data)
    {
        std::cout<<"I am the SecondObserver and data is "<<data<<std::endl;
    }
    ~SecondObserver()
    {
        std::cout<<" SecondObserver destroyed "<<std::endl;
    }
};
class ThirdObserver : public ObserverBase
{
public:
    void update(int data)
    {
        std::cout<<"I am the ThirdObserver and data is "<<data<<std::endl;
    }
    ~ThirdObserver()
    {
        std::cout<<" ThirdObserver destroyed "<<std::endl;
    }
};
#endif
