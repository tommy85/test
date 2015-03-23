#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <unistd.h>


class parent;
class children;

typedef boost::shared_ptr<parent> parent_ptr;
typedef boost::shared_ptr<children> children_ptr;

class parent
{
public:
	 ~parent() { std::cout <<"destroying parent\n"; };
	 void do_something(){std::cout <<"do parent"<<std::endl;};

public:
    children_ptr m_children;
};

/*
class children
{
public:
    ~children() { std::cout <<"destroying children\n"; }

public:
    parent_ptr parent;
};
*/

class children
{
public:
	 children(parent_ptr & _parent):m_parent(_parent){};
    ~children() { std::cout <<"destroying children\n"; }
	 void do_something(){std::cout <<"do children"<<std::endl; };

public:
    boost::weak_ptr<parent> m_parent;
};


void test()
{
    parent_ptr father(new parent());
    children_ptr son(new children(father));

    father->m_children = son;
//    son->parent = father;
//	son->m_parent(father);
//	father.reset();
//	son.reset();
//	sleep(5);
	
//	parent_ptr tmpparent = son->m_parent.lock();
	parent *tmpparent = son->m_parent.get();
	if (tmpparent)
	{
		 tmpparent->do_something();
	}
}

int main()
{
    std::cout<<"begin test...\n";
    test();
    std::cout<<"end test.\n";
}
