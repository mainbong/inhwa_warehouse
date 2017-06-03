#include <iostream>
using namespace std;

int x = 10;

int& foo(int a) { return x; }

/*
// f()�� ������ �����ϸ� ������ �ȴ�.
template<typename F, typename T> auto logTime(F f, T a)
{
	return f(a);
}
*/

// f()�� ���������� ��츦 ����ؼ� �Ʒ�ó�� �ؾ� �մϴ�.
// C++14
/*
template<typename F, typename T>
decltype(auto) logTime(F f, T a)
{
	return f(a);
}
*/
// C++14�� ����Ҽ� ���� ȯ���̶�� �Ʒ� ó�� �ϸ� C++11�� �˴ϴ�.
// f()�� ���������� �ص� ��Ȯ�� ���޵˴ϴ�.
template<typename F, typename T>
auto logTime(F f, T a) -> decltype(f(a))
{
	return f(a);
}

// g++ �ҽ��̸�.cpp --std=c++11      C++11��������
// g++ �ҽ��̸�.cpp --std=c++1y      C++14��������

int main()
{
	int& k = logTime(foo, 10);

	k = 20;

	cout << x << endl; 
	
}





