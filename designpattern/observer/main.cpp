#include "Observer.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>


using namespace std;


#include <stdlib.h>

ConcreteObserverA p4;

int main()
{

	 Observer* p1 = new ConcreteObserverA();
	 Observer* p2 = new ConcreteObserverB();
	 Observer* p3 = new ConcreteObserverA();
	 //delete p1;
	 //delete p2;
	 //delete p3;
	 exit(0);

	 Subject* pSubject = new ConcreteSubjectA();
	 Subject* pSubjectB = new ConcreteSubjectB();
	 pSubject->Attach(p1);
	 pSubject->Attach(p2);
	 pSubject->Attach(p3);

	 pSubjectB->Attach(p1);
	 pSubjectB->Attach(p2);
	 pSubjectB->SetState("new");
	 pSubjectB->Notify();
	 

	 cout << "-------------------------------------" << endl;
	 pSubject->SetState("old");

	 pSubject->Notify();

	 cout << "-------------------------------------" << endl;
	 pSubject->SetState("new");

	 pSubject->Detach(p3);
	 pSubject->Notify();

	 delete p1;
	 delete p2;
	 delete p3;
	 delete pSubject;


    return 0;
}
