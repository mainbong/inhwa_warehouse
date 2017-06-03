#include "show.h"

int main()
{
	list<int> s = { 1,3,5,7,9,2,4,6,8,10 };

	// s를 sort 하고 싶다.
	sort(s.begin(), s.end());

	show(s);
}