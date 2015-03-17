#include "Iterator.h"
#include <iostream>

int main()
{
	 Aggregate* pAggregate = new ConcreateAggregate(4);
//	 Iterater* pIterater = new ConcreateIterater(pAggregate);
	 Iterater* pIterater = pAggregate->CreateIterater();

	 for (; false == pIterater->IsDone(); pIterater->Next())
	 {
		  std::cout << pIterater->CurrentItem() << std::endl;
	 }

	 return 0;
}
