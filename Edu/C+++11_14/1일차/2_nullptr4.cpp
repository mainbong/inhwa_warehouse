// 2_nullptr4
#include <iostream>
using namespace std;

// nullptr의 정체
int main()
{
	// nullptr_t 타입의 객체!!
	nullptr_t a = nullptr;

	// nullptr_t 타입
	// 1. 모든 타입 포인터로 암시적 변환
	// 2. bool 로 암시적 변환
	// 3. int로 변환 안됨. 하지만 명시적 변환은 허용
	char* p1 = nullptr;
//	int   n = nullptr; // error
	bool  b = nullptr;

	int n2 = reinterpret_cast<int>(nullptr); // ok
}






