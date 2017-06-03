// 9_반복자 어답터
#include "show.h"

// reverse_iterator원리
/*
template<typename T> class reverse_iterator
{
	T& p; // 기존 반복자
public:
	reverse_iterator(T& t) : p(t) {}

	reverse_iterator& operator++()
	{
		--p;
		return *this;
	}
};
*/

int main()
{
	list<int> s = { 1,2,3,1,2,3,4,5 };
//  list<int>::iterator p = s.begin();
//	list<int>::reverse_iterator p = s.rbegin();
//  list<int>::const_iterator p = s.cbegin();
//	list<int>::const_reverse_iterator p = s.crbegin();

	//*p = 20; // error
	//++p;
	//cout << *p << endl;

	list<int>::iterator p = find(s.begin(), s.end(), 2);

	cout << *p << endl;

	// 뒤에서 부터 찾아보세요.
	list<int>::reverse_iterator p2 = find(s.rbegin(), s.rend(), 2);
}