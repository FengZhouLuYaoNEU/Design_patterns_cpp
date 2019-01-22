#include <iostream>
#include <pthread.h>
#include <unistd.h>

class NewSingleton
{
private:
  NewSingleton(){}
public:
  static NewSingleton * getInstance()
  {
    static NewSingleton instance;
    return &instance;
  }
};
void* fun1(void *)
{
    while(1)
    {
        NewSingleton * pt = NewSingleton::getInstance();
        std::cout << "fun1: pt_addr = " << pt << std::endl;
        sleep(2);
    }
    return NULL;
}

void* fun2(void *)
{
    while(1)
    {
        NewSingleton * pt = NewSingleton::getInstance();
        std::cout << "fun2: pt_addr = " << pt << std::endl;
        sleep(2);
    }
    return NULL;
}
void* fun3(void *)
{
    while(1)
    {
        NewSingleton * pt = NewSingleton::getInstance();
        std::cout << "fun3: pt_addr = " << pt << std::endl;
        sleep(2);
    }
    return NULL;
}
int main(int argc, char** argv) {
    pthread_t pt_1 = 0;
    pthread_t pt_2 = 0;
    pthread_t pt_3 = 0;
    int ret = pthread_create(&pt_1,0,&fun1,0);
    if(ret != 0)
    {
        std::cout<<("error\n");
    }
    ret = pthread_create(&pt_2,0,&fun2,0);
    if(ret != 0)
    {
        std::cout<<("error\n");
    }
    ret = pthread_create(&pt_3,0,&fun3,0);
    if(ret != 0)
    {
        std::cout<<("error\n");
    }
    pthread_join(pt_1,0);
    pthread_join(pt_2,0);
    pthread_join(pt_3,0);
    
    return 0;
}
