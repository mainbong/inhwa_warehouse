// CPP11_컨테이너
#include "show.h"

// 선형 컨테이너: vector, list, deque - C++98
// C++11 : forward_list

#include <forward_list>
int main()
{
	forward_list<int> s;
	s.push_front(10);
	show(s);
}