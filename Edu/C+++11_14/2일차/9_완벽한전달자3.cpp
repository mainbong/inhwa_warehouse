#include <iostream>
using namespace std;

// 해결책 2. 이동 가능한 참조 만들기

// 참조와 포인터는 모두 기존 메모리를 가르키게 됩니다.

// 대입연산시에..
// 참조   : 값이 이동.        값을 꺼낼때 *를 할 필요없다.
// 포인터 : 참조(주소)가 이동. 값을 꺼낼때 *를 해야 한다.


int main()
{
	int n1 = 10;
	int n2 = 20;

	int& r1 = n1;
	int& r2 = n2;

	r1 = r2; // 값이동

	// 결과 예측해 보세요 
	cout << n1 << endl; // 20
	cout << n2 << endl; // 20
	cout << r1 << endl; // 20
	cout << r2 << endl; // 20
}





