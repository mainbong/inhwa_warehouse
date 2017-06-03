//6_begin
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// �Ϲ��Լ� begin
template<typename T> auto begin(T& c) {	return c.begin();}
template<typename T> auto end(T& c) { return c.end(); }

template<typename T, int N> auto begin(T(&c)[N]) { return c; }
template<typename T, int N> auto end(T(&c)[N]) { return c[N]; }
*/

// show.h ���� show() �Լ� ������ ������.
template<typename T> void show(T& c)
{
	auto p = begin(c); // c.begin();
	while (p != end(c))
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

int main()
{
	vector<int> v = { 1,2,3,4,5 };

	show(v);

	int x[5] = { 1,2,3,4,5 };
	show(x); // ???
}
