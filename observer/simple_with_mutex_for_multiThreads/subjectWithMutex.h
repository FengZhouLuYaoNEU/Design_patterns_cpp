#ifndef SUBJECT_WITH_MUTEX_H_ 
#define SUBJECT_WITH_MUTEX_H_

#include "observer.h"
#include <vector>
#include <algorithm>
#include <mutex> 
class SubjectObservedWithMutex
{
public:
    SubjectObservedWithMutex():data(100)
    {
    }
    void registerObjs(ObserverBase * obj)
    {
        mutex.lock();
        objs.push_back(obj);
        mutex.unlock();
    }
    void notifyAllObjs()
    {
        mutex.lock();
        for (auto obj : objs)
        {
            obj->update(data);
        }
        mutex.unlock();
    }
    void setData(int data_)
    {
        data = data_;
    }
    void unregister(ObserverBase * obj)
    {
        mutex.lock();
        auto result = std::find(std::begin(objs), std::end(objs), obj);
        if (result != std::end(objs))
        {
            objs.erase(result);
            delete obj;
        }
        mutex.unlock();
    }
    ~SubjectObservedWithMutex()
    {
        for (auto obj : objs)
        {
            if (obj != nullptr)
            {
                delete obj;
            }
        }
    }
private:
    std::mutex  mutex;
    std::vector<ObserverBase *> objs;
    int data;   
};
#endif
