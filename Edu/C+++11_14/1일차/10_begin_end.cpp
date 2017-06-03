//10_begin_end - 19 page �׸�2-3

#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// ��� �����̳��� ��Ҹ� ����ϴ� �Լ�
template<typename T> void show(T& c)
{
	//typename T::iterator p = c.begin();
	auto p = c.begin();

	while (p != c.end())
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}
int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	show(v); 
	show(x);
}