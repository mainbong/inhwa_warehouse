// 3_const - 60 page
#include <iostream>
using namespace std;

// C++98/03 에서 const의 문제점
int main()
{
	//const int c = 10; // compile time constant
						// 앞으로 c가 나오면 매크로 처럼 10으로 컴파일 시간에
						// 치환된다.
	int n = 10;
	cin >> n;
	const int c = n; // Run time constant
					 // 컴파일 시간에는 값을 알수 없다.


	//int* p = &c; // error. 비상수 포인터에 상수의 주소를 담을수 없다.

	int* p = (int*)&c; // 또는 const_cast<int*>(&c);
						// 명시적 변환은 허용된다.
	*p = 20;

	cout << c  << endl; // 10
	cout << *p << endl; // 20
}







