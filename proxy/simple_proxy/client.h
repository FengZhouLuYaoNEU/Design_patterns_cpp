#ifndef CLIENT_H_
#define CLIENT_H_

#include <vector>
#include "proxy.h"
class NorthKoreaClient
{
public:
    std::string visitFaceBook()
    {
        ProxyServer* selectedServer = nullptr;
        Iterator it = proxyServers.begin();
        while (it != proxyServers.end())
        {
            if((*it))
            {
                if ((*it)->isServerOnline())
                {
                    selectedServer = *it;
                    break;
                }
            }
            it++;           
        }
        if (selectedServer)
        {
            return selectedServer->visitFaceBook();
        }
        else
        {
            return std::string("Facebook site can not acess !!!!");
        }
    }
    void buyVpnService(int dollar, ProxyServer * vpn)
    {
        proxyServers.push_back(vpn);
    }
private:
    std::vector<ProxyServer*>  proxyServers;
    typedef std::vector<ProxyServer*>::iterator Iterator; 
};
#endif
