#include "show.h"

int main()
{
	int x[3] = { 1,2,3 };

	// C++11 auto : ������ �ÿ� �캯�� Ÿ���� �����ؼ� �º��� �����ش޶�
	auto n = x[0];

	vector<int> v = { 1,2,3 };

	vector<int>::value_type n1 = v.front();

	vector<int>::iterator p = v.begin();
	auto p = v.begin();
}