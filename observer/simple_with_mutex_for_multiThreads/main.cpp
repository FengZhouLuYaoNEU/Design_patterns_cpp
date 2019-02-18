#include <iostream>
#include "subjectWithMutex.h"
#include <thread>
#include <functional>

void func(ObserverBase * base,SubjectObservedWithMutex & subject)
{
    subject.registerObjs(base);
}
int main(int argc, char** argv) {
    
    ObserverBase * first  = new FirstObserver;
    ObserverBase * second = new SecondObserver;
    ObserverBase * third  = new ThirdObserver;
    SubjectObservedWithMutex subj;
    std::thread t1(func,first,std::ref(subj));
    subj.notifyAllObjs();
    t1.join();
    std::thread t2(func,second,std::ref(subj));
    subj.notifyAllObjs();
    t2.join();
    std::thread t3(func,third,std::ref(subj));
    subj.notifyAllObjs();
    t3.join();
    subj.notifyAllObjs();
    subj.setData(200);
    subj.notifyAllObjs();
    return 0;
}
