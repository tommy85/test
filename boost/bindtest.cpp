#include <boost/bind.hpp>
#include <boost/function.hpp>
#include<iostream>

using namespace std;

class testfunc
{
public:
	 testfunc(){}
	 ~testfunc(){}
	 int subfunc(int a,int b)
	 {
		  return a-b;		  
	 }
};

typedef boost::function<int (int,int)> Func;
//typedef boost::function<int ()> Func;

int addfunc(int a,int b)
{
	 return a+b;
}
int main()
{
	 Func f;
	 //f = &addfunc;
	 f = boost::bind(addfunc,_1,_2);
	 cout<<f(3,4)<<endl;

	 //f = boost::bind(addfunc,3,10);
	 //cout<<f()<<endl;


	 Func fc;
	 testfunc testc;
	 fc = boost::bind(&testfunc::subfunc,&testc,_1,_2);
	 cout<<fc(7,2)<<endl;
}
