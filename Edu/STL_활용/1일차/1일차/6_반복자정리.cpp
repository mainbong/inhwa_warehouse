// 6_반복자정리
#include "show.h"

int main()
{
	vector<int> v(10, 3); // 10개를 3으로 초기화
	vector<int>::iterator p = v.begin();

	cout << *p << endl;

	//v.resize(20); // 이 순간 미리 꺼내 놓은 반복자는 무효화 됩니다.
				  // 사용하면 안됩니다.

	v.resize(5); // ?
	
	cout << v.size() << endl; //5
	cout << v.capacity() << endl; // 10

	cout << *p << endl; // ???
}