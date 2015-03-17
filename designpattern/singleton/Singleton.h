#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include "pthread.h"

class Singleton
{
private:
	static Singleton* pInstance1;
    //static Singleton* pInstance;//静态成员，保存对象的唯一实例
    Singleton();//私有化构造函数，使其无法在类外实例化
	static pthread_mutex_t lock;

public:
	static Singleton* Instance();
    //void Destroy();
    static void Destroy();
};

#endif
