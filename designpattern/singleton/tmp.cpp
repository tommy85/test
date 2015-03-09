#include<iostream>

using namespace std;


class Singleton
{
private:
    static Singleton* pInstance;//静态成员，保存对象的唯一实例
    Singleton();//私有化构造函数，使其无法在类外实例化
public:
    static Singleton* Instance();
    //void Destroy();
    static void Destroy();
};


Singleton::Singleton()
{
	 cout<<"singleton"<<endl;
};

/*
Singleton* Singleton::Instance()
{
	 if(pInstance == NULL)
	 {
		  pInstance = new Singleton();
	 }
	 return pInstance;
};
*/

Singleton* Singleton::Instance()
{
    if(NULL == pInstance)
    {
        pInstance = new Singleton();
    }
    return pInstance;
}

Singleton* Singleton::pInstance = NULL;

int main()
{
    Singleton* ps = Singleton::Instance();//通过全局访问点获取实例
	// Singleton::Destroy();
    return 0;
}
