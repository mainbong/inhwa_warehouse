// 3_컨테이너2
#include "show.h"

// vector, deque	: 임의접근 반복자
// list				: 양방향 반복자

// 3개 컨테이너의 사용법은 거의 유사합니다.

int main()
{
	// 1.생성
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,3);
	vector<int> v14(v3);
	vector<int> v5 = { 1,2,3 }; // C++ 11 부터 가능.
/*
	// 2. 요소 추가
	v1.push_back(10);
	//v1.push_front(20); // vector 만 error
	v1.insert(v1.begin() + 1, 20);

	// 3. 제거
	v1.pop_back();
	v1.erase(v1.begin());
	v1.erase(find(v1.begin(), v1.end(), 10), v1.end());

	// 4. 요소 접근
	v1.front() = 40;

	// []와 at()은 vector와 deque만 가능.
	v1[0] = 40;
	v1.at(0) = 40;
	*/
	vector<int> v8(10);
	try {
		v8.at(11) = 20;
	}
	catch (out_of_range& e)
	{
		cout << "예외 발생" << endl;
	}
	for (int i = 0; i < v8.size(); i++)
	{
		v8.at(i) = 0;	// 1. 좋지않다. i 가 잘못될 경우가 없다.
		v8[i] = 0;		// 2
	}
	
}