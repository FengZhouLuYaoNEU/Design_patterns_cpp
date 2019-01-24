#ifndef PROXY_H_
#define PROXY_H_
#include <string>
class ProxyServer
{
public:
    virtual std::string visitFaceBook() = 0;
    virtual bool  isServerOnline() = 0;
    virtual ~ProxyServer(){}    
};
class JapanVPN :public ProxyServer
{
public:
    JapanVPN():isOnline(true){}
    std::string visitFaceBook()
    {
        return  std::string("Welcome to visit Facebook!!!");
    }
    bool  isServerOnline()
    {
        return isOnline;
    }
private:
    bool isOnline;
};
class SingaporeVPN :public ProxyServer
{
public:
    SingaporeVPN():isOnline(true){}
    std::string visitFaceBook()
    {
        return  std::string("Welcome to visit Facebook!!!");
    }
    bool  isServerOnline()
    {
        return isOnline;
    }
private:
    bool isOnline;
};
#endif
