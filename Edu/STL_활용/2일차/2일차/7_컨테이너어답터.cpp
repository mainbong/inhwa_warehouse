// 7_컨테이너어답터
#include "show.h"

// list가 있는데 .. stack 이 필요하다.
// 1. stack 을 다시 만들자
// 2. list를 한쪽으로 사용하면 stack 이다. list 를 재사용하자.
// Adapter 패턴 : 기존 클래스의 인터페이스(함수이름)을 변경해서
//				다른 클래스처럼 보이게 하는 기술.
/*
template<typename T> class stack : public list<T>
{
public:
	inline void push(const T& a)	{	list<T>::push_back(a);	}
	inline void pop()				{list<T>::pop_back();}
	inline T top()					{ return list<T>::back(); }
};
*/

#include <deque>
// 상속보다는 포함이 더 깔끔한 디자인을 만들 수 있을때도 있다.
/*
template<typename T, typename C = deque<T>> class stack
{
	C st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline void pop() { st.pop_back(); }
	inline T top() { return st.back(); }
};
*/

#include <stack>

int main()
{
	stack<int, list<int, MyAlloc<int>>> s2;
	stack<int, vector<int>> s;
	s.push(10);
	s.push(20);

	//s.push_front(30); // 사용자가 실수 했다. 이 함수를 쓸수 없게 하고싶은데 ?
	cout << s.top() << endl;
}