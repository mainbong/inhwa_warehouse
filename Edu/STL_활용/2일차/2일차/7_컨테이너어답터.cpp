// 7_�����̳ʾ����
#include "show.h"

// list�� �ִµ� .. stack �� �ʿ��ϴ�.
// 1. stack �� �ٽ� ������
// 2. list�� �������� ����ϸ� stack �̴�. list �� ��������.
// Adapter ���� : ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ�
//				�ٸ� Ŭ����ó�� ���̰� �ϴ� ���.
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
// ��Ӻ��ٴ� ������ �� ����� �������� ���� �� �������� �ִ�.
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

	//s.push_front(30); // ����ڰ� �Ǽ� �ߴ�. �� �Լ��� ���� ���� �ϰ������ ?
	cout << s.top() << endl;
}