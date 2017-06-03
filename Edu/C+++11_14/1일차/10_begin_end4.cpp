//10_begin_end - 19 page 항목2-3

#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// 결론 : ranged -for 가 제일 편리하다.
template<typename T> void show(T& c)
{
	for (auto n : c)
		cout << n << " ";

	cout << endl;
}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	show(v);
	show(x);
}