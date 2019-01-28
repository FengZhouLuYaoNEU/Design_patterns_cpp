#include <iostream>
#include "adapter.h"
 using namespace std::placeholders;
int main(int argc, char** argv)
{
    ThirdPartComponent thirdCom;
    Client  * client = new Adapter(thirdCom);
    client->action(1000);
    delete client;
    
    
    auto func = std::bind(&ThirdPartComponent::specificAction,thirdCom,_1);
    TAdapter<decltype(func),void,int> tAdapter(func);
    tAdapter.func(10000000);
    
//    PerfectForward<decltype(func),int>(func,10000000);
    return 0;
}
