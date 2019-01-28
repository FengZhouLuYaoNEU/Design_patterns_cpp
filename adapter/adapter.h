#ifndef ADAPTER_H_
#define ADAPTER_H_
#include <iostream>
#include <functional>
#include <initializer_list>
#include <utility>
class Client
{
public:
    virtual void action(int data)
    {
        std::cout<<data*2<<std::endl;
    }
    virtual ~Client(){}
};
class ThirdPartComponent
{
public:
    void specificAction(int data)
    {
        std::cout<<data*200<<std::endl;
    }   
};
//do not change the client interface and add a adapter
class Adapter :public Client
{
public:
    Adapter(ThirdPartComponent & tpc_):tpc(tpc_)
    {
    }
    void action(int data)
    {
        tpc.specificAction(data);
    }
private:
    ThirdPartComponent & tpc;
};

template<typename TPC_FUNC, typename RET, typename ... Args>
class TAdapter
{
public:
    TAdapter(TPC_FUNC func):TPC_Func(func)
    {
    }
    RET func(Args&&... args)
    {
        return TPC_Func(std::forward<Args>(args)...);
    }
private:    
    TPC_FUNC TPC_Func;
};

/* decltype(auto)  from C++14
template<class F, class... Args>
decltype(auto) PerfectForward(F fun, Args&&... args) 
{ 
    return fun(std::forward<Args>(args)...); 
}
*/
#endif
