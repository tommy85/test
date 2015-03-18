#include<iostream>
#include<map>
#include<iterator>
#include <algorithm>

using namespace std;
#define DWORD int

struct AAA
{
	 DWORD aaa;
	 int bbb;
	 AAA(DWORD a,int b):aaa(a),bbb(b){};
};
struct iter
{
	 bool operator()(const AAA *s1,const AAA *s2)
		  {
			   return s1->aaa<s2->aaa;
		  }
};
typedef map<int,string>::value_type type;
void func(type &k)
{
	 cout<<k.first<<" "<<k.second<<endl;
}
int main()
{
	 std::less<int> i;
	 //AAA a(4,1);
	 //AAA b(5,3);
	 // int a =4;
	 // int b=5;
	 // if (i(a,b))
	 // {
	 // 	  cout<<"a<b"<<endl;
	 // 	  return 0;
	 // }
	 /*
	 map<AAA*,int,iter> temp;
	 temp.insert(make_pair(&AAA(1,5),1));
	 temp.insert(make_pair(&AAA(2,4),2));
	 temp.insert(make_pair(&AAA(3,3),3));
	 temp.insert(make_pair(&AAA(4,2),4));
	 temp.insert(make_pair(&AAA(5,1),5));
	 map<AAA*,int,iter>::iterator it=temp.begin();
	 */
	 map<int,string> temp;

	 temp.insert(make_pair(5,"c"));
	 temp.insert(make_pair(4,"b"));
	 temp.insert(make_pair(3,"a"));
	 map<int,string>::iterator it=temp.begin();
	 /*
	 while(it!=temp.end())
	 {
		  cout<<it->first<<" "<<it->second<<endl;
		  it++;
	 }
	 */
	 //for_each(it,temp.end(),func);
	 cout<<temp.find(4)->second<<endl;
	 cout<<temp[4]<<endl;
	 return 0;
}
