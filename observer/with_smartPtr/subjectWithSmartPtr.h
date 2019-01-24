#ifndef SUBJECT_WITH_SMART_PTR_H_ 
#define SUBJECT_WITH_SMART_PTR_H_

#include "observer.h"
#include <vector>
#include <algorithm>
#include <mutex>
#include <memory> 
class SubjectObservedWithSmartPtr
{
public:
    SubjectObservedWithSmartPtr():data(100)
    {
    }
    void registerObjs(std::weak_ptr<ObserverBase>  obj)
    {
        mutex.lock();
        objs.push_back(obj);
        mutex.unlock();
    }
    void notifyAllObjs()
    {
        mutex.lock();
        for (Iterator it = objs.begin(); it != objs.end();)
        {
            std::shared_ptr<ObserverBase> obj(it->lock());
            if (obj) 
            {
                obj->update(data);
                it++;
            }
            else
            {
                it = objs.erase(it);    
            }           
        }
        mutex.unlock();
    }
    void setData(int data_)
    {
        data = data_;
    }
    ~SubjectObservedWithSmartPtr()
    {
    }
private:
    std::mutex  mutex;
    std::vector<std::weak_ptr<ObserverBase> > objs;
    typedef std::vector<std::weak_ptr<ObserverBase> >::iterator Iterator;
    int data;   
};
#endif
