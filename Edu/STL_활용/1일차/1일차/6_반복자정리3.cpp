#include "show.h"

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	slist<int>::iterator p = s.begin();
	
	++p; // ok..
	--p; // µÉ±î¿ä ?
}