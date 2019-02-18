#ifndef SUBJECT_H_ 
#define SUBJECT_H_

#include "observer.h"
#include <vector>
#include <algorithm>
class SubjectObserved
{
public:
    SubjectObserved():data(100)
    {
    }
    void registerObjs(ObserverBase * obj)
    {
        objs.push_back(obj);
    }
    void notifyAllObjs()
    {
        for (auto obj : objs)
        {
            obj->update(data);
        }
    }
    void setData(int data_)
    {
        data = data_;
    }
    void unregister(ObserverBase * obj)
    {
        auto result = std::find(std::begin(objs), std::end(objs), obj);
        if (result != std::end(objs))
        {
            objs.erase(result);
            delete obj;
        }
    }
    ~SubjectObserved()
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
    std::vector<ObserverBase *> objs;
    int data;   
};
#endif
