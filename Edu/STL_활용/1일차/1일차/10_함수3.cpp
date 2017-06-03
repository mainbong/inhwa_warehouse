// 10_�Լ�3
#include "show.h"

int foo(int a, int b) 
{ 
	cout << "foo" << endl;
	return a + b; 
}

/*
template<typename T> struct Plus
{
	inline T operator()(T a, T b) { return a + b; } // �̹� �����Ѵ�!
};
*/
#include <functional> //STL �� �����ϴ� �Լ� ��ü
/*
struct Plus
{
	inline int operator()(int a, int b) { return a + b; }
};
*/
int main()
{
	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 1,2,3,4,5 };

	vector<int> v(5, 0);

	// �Ϲ� �Լ��� �˰��� ���ڷ� ������ �ζ��� ġȯ�� �ȵȴ�.  - ������.
	// transform(x, x + 5,y, v.begin(), foo);

	// �Լ���ü�� ����ϸ� �ζ��� ġȯ�ȴ�. - ������.
	plus<int> p;
	transform(x, x + 5, y, v.begin(), p);

	show(v);
}