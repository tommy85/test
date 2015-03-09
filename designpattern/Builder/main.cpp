#include "Builder.h"
#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

using namespace std;

int main()
{
	 //Director* pDirector = new Director(new ConcreteBuilder1());
	 //boost::scoped_ptr<Director> pDirector(new Director(new ConcreteBuilder1()));
	boost::shared_ptr<Director> pDirector(new Director(new ConcreteBuilder1()));
    Product *pProduct = pDirector->Construct();
	pProduct->output();
	pDirector.reset();

    Director* pDirector1 = new Director(new ConcreteBuilder2());
    Product *pProduct1 = pDirector1->Construct();
	pProduct1->output();

    return 0;
}
