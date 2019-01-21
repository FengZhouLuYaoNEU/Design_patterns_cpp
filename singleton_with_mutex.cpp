#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <mutex>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

template<typename T>
class Singleton
{
	public:
		Singleton()  = delete;
		~Singleton() = delete;
		static T & getInstance()
		{
		  if (value == nullptr)
          {
            mutex.lock();
            if (value == nullptr)
            {
              value = new T();
              ::atexit(destroy);
            }
           mutex.unlock();
          }
	      return *value;
		}
    private:
    	static void destroy()
    	{
    		delete value;
		}
	private:
		static T *    value;
		static std::mutex  mutex;
};
template<typename T>
std::mutex Singleton<T>::mutex;
template<typename T>
T* Singleton<T>::value = nullptr;

class Test_Singleton
{
	public:
		Test_Singleton():a(100)
		{
			std::cout<<"Test_Singleton  constructor"<<std::endl;
		}
		~Test_Singleton()
		{
			std::cout<<"Test_Singleton  destroying"<<std::endl;
		}
	private:
		int a;
};
void* fun1(void *)
{
    while(1)
    {
        Test_Singleton& pt = Singleton<Test_Singleton>::getInstance();
        std::cout << "fun1: pt_addr = " << &pt << std::endl;
        sleep(5);
        break;
    }
    return NULL;
}
void* fun2(void *)
{
    while(1)
    {
        Test_Singleton& pt = Singleton<Test_Singleton>::getInstance();
        std::cout << "fun2: pt_addr = " << &pt << std::endl;
        sleep(5);
        break;
    }
    return NULL;
}
void* fun3(void *)
{
    while(1)
    {
        Test_Singleton& pt = Singleton<Test_Singleton>::getInstance();
        std::cout << "fun3: pt_addr = " << &pt << std::endl;
        sleep(5);
        break;
    }
    return NULL;
}

int main(int argc, char** argv) {
	pthread_t pt_1 = 0;
    pthread_t pt_2 = 0;
    pthread_t pt_3 = 0;
    int ret = pthread_create(&pt_1,0,&fun1,0)
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
