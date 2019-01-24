#include <iostream>
#include "subjectWithSmartPtr.h"
#include <thread>
#include <functional>

void func(std::weak_ptr<ObserverBase> base,SubjectObservedWithSmartPtr & subject)
{
    subject.registerObjs(base);
}
int main(int argc, char** argv) {
    
    std::shared_ptr<ObserverBase>  first  = std::make_shared<FirstObserver>();
    std::shared_ptr<ObserverBase>  second = std::make_shared<SecondObserver>();
    std::shared_ptr<ObserverBase>  third  = std::make_shared<ThirdObserver>();
    SubjectObservedWithSmartPtr subj;
    std::thread t1(func,first,std::ref(subj));
    subj.notifyAllObjs();
    t1.join();
    std::thread t2(func,second,std::ref(subj));
    subj.notifyAllObjs();
    t2.join();
    std::thread t3(func,third,std::ref(subj));
    subj.notifyAllObjs();
    first.reset();
    t3.join();
    subj.notifyAllObjs();
    subj.setData(200);
    subj.notifyAllObjs();
    return 0;
}
