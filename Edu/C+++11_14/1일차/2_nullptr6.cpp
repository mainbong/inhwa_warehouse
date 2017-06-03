#include <iostream>
using namespace std;

// 17 page - 중요한 예제 입니다.
int  foo(int* p, int n)
{
	for (int i = 0; i < 10000; i++)
		cout << "*";
	cout << endl;
	return 10;
}

#include "logTime.h" // 카페에서 다운 받으세요 
					 // cafe.naver.com/cppmaster
					 // 현재 프로젝트 폴더에 복사해 두세요..
int main()
{
	// 주의 ! 포인터 0 대신 nullptr 사용해야 합니다.
	int n = logTime(foo, nullptr, 10); 
}





