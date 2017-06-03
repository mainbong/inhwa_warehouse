#include <iostream>
using namespace std;

// 해결책 2. 이동 가능한 참조 만들기

// 값이 아닌 참조가 이동하는 참조!!
template<typename T> class xreference_wrapper
{
	// 결국 참조는 다른 변수를 가르켜야 합니다... 포인터필요
	T* obj;
public:
	xreference_wrapper(T& r) : obj(&r) {}

	// C++의 일반 참조로 암시적 변환 가능하게 한다.
	operator T&() { return *obj; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;
	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;
	r1 = r2; // ???

	int& r3 = r1; // r1은 진짜 참조로도 변환됩니다.

	// 결과 예측해 보세요 
	cout << n1 << endl; // 10
	cout << n2 << endl; // 20
	cout << r1 << endl; // 20
	cout << r2 << endl; // 20
						// C++ 컴파일러는 r1 자체는 cout으로 출력 할수 없지만
						// 출력 가능한 타입으로 변환이 가능한지를 조사한다.
						// int&로 변환 가능하므로 변환해서 출력된다.
}





