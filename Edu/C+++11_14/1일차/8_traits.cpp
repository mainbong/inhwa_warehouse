// 8_traits - 8 page
#include <iostream>
using namespace std;

// Traits : T의 다양한 속성(특질)을 조사하는 기술
//			2000년 초반에 나와서 C++11에서 공식 표준으로 채택됨.!
template<typename T> void printv(T v)
{
	if (T is Pointer)
		cout << v << ", " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	double d = 3.4;
	int    n = 3;
	printv(d);
	printv(n);
	printv(&n);
}





