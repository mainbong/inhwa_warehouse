#include "show.h"

int main()
{
	int x[3] = { 1,2,3 };

	// C++11 auto : 컴파일 시에 우변의 타입을 조사해서 좌변을 결정해달라
	auto n = x[0];

	vector<int> v = { 1,2,3 };

	vector<int>::value_type n1 = v.front();

	vector<int>::iterator p = v.begin();
	auto p = v.begin();
}