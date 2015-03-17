#include "Singleton.h"
#include <iostream>

using namespace std;

Singleton* Singleton::pInstance1 = NULL;
pthread_mutex_t Singleton::lock = PTHREAD_MUTEX_INITIALIZER;

Singleton::Singleton()
{
    cout<< "Singleton..." << endl;
}

Singleton* Singleton::Instance()
{
	 if(NULL == pInstance1)
	 {
		  //Double-checked Locking
		  pthread_mutex_lock(&lock);
		  if (NULL == pInstance1)
		  {
			   pInstance1 = new Singleton();
		  }
		  pthread_mutex_unlock(&lock);
	 }
	 return pInstance1;
}

void Singleton::Destroy()
{
    delete pInstance1;
    pInstance1 = NULL;
    cout<< "Destroy..." << endl;
}
