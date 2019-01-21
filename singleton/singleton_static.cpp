#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <mutex>
class SingletonStatic
{
private:
static const SingletonStatic *m_instance;
SingletonStatic(){}
public:
static const SingletonStatic *getInstance()
{
    return m_instance;
}
};

const SingletonStatic *SingletonStatic::m_instance = new SingletonStatic;

std::mutex mutex;

void* fun1(void *)
{
  while(1)
  {
    const SingletonStatic* pt = SingletonStatic::getInstance();
    mutex.lock();
    std::cout << "fun1: pt_addr = " << &pt << std::endl;
    mutex.unlock();
    sleep(5);
   // break;
  }
  return NULL;
}
void* fun2(void *)
{
  while(1)
  {
    const SingletonStatic* pt = SingletonStatic::getInstance();
    mutex.lock();
    std::cout << "fun2: pt_addr = " << &pt << std::endl;
    mutex.unlock();
    sleep(2);
    //break;
  }
  return NULL;
}
void* fun3(void *)
{
  while(1)
  {
    const SingletonStatic* pt = SingletonStatic::getInstance();
    mutex.lock();
    std::cout << "fun3: pt_addr = " << &pt << std::endl;
    mutex.unlock();
    sleep(1);
   // break;
  }
  return NULL;
}

int main(int argc, char** argv) {
    pthread_t pt_1 = 0;
    pthread_t pt_2 = 0;
    pthread_t pt_3 = 0;
    int ret = pthread_create(&pt_1,0,&fun1,0);
    if (ret != 0)
    {
      std::cout<<("error\n");
    }
    ret = pthread_create(&pt_2,0,&fun2,0);
    if (ret != 0)
    {
      std::cout<<("error\n");
    }
    ret = pthread_create(&pt_3,0,&fun3,0);
    if (ret != 0)
    {
      std::cout<<("error\n");
    }
    pthread_join(pt_1,0);
    pthread_join(pt_2,0);
    pthread_join(pt_3,0);

    return 0;
}
