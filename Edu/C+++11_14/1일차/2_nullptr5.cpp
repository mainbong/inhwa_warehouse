#include <iostream>
using namespace std;
// 17 page - 중요한 예제 입니다.
void foo(int* p)
{
	for (int i = 0; i < 10000; i++)
		cout << "*";
	cout << endl;
}

// 특정 함수의 성능을 측정하는 래퍼를 만들어 봅시다.
template<typename F, typename T> void logTime(F f, T a)
{
	// 시간을 기록해 놓고
	f(a); 
	// 현재 시간을 얻은후.. 걸린 시간 측정..
}
int main()
{
	foo(0);    // ok..
	foo(NULL); // ok
//	logTime(foo, 0);    // 함수, 함수인자, error
//	logTime(foo, NULL); // error

	// logTime 같은 래퍼 함수를 사용하려면 0대신 nullptr밖에 안됩니다.
	// 교재는 logTime 대신 lockAndCall()입니다 - 17 page
	logTime(foo, nullptr); // ok

}





