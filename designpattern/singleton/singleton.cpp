#include "Singleton.h"
#include <iostream>

using namespace std;

Singleton* Singleton::pInstance = NULL;

Singleton::Singleton()
{
    cout<< "Singleton..." << endl;
}

Singleton* Singleton::Instance()
{
    if(NULL == pInstance)
    {
		 //Double-checked Locking
		 //lock();
		 if (NULL == pInstance)
		 {
			  pInstance = new Singleton();
		 }
		 //unlock();
    }
    return pInstance;
}

void Singleton::Destroy()
{
    delete pInstance;
    pInstance = NULL;
    cout<< "Destroy..." << endl;
}
