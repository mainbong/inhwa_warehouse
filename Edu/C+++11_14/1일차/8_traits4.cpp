// traits1번 복사해오세요
#include <iostream>
using namespace std;

template<typename T> struct IsPointer { enum { value = false }; };
template<typename T> struct IsPointer<T*> { enum { value = true }; };

// T가 포인터 인 경우와 그렇지 않은 경우에 처리할 함수를 2개 만든다. - 오버로딩
template<typename T> void printvImp(T a, YES)
{
	cout << "포인터인 경우" << endl;
	cout << v << ", " << *v << endl;
}
template<typename T> void printvImp(T a, NO)
{
	cout << "포인터가 아닌 경우" << endl;
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	// T가 포인터 인지에 따라 함수 오버로딩 사용
	printvImp(v, ? ? );

	// 함수 오버로딩에 의한 함수 선택 : 컴파일 시간에 결정됩니다.
	//						결정되지 않은 함수템플릿은 인스턴스화 되지 않습니다.

	// if문에 의한 함수 선택 : 실행시간에 결정됩니다.
	//						아래 코드가 컴파일 시간에 true가 나와도
	//						결국 호출은 실행시간 이므로
	//						printvImp(YES), printvImp(NO) 버전이
	//						모두 인스턴스화(실제 함수로 만드는것)가 됩니다.
	//						그럼, int인 v를 *v하므로 다시error


	/*
	if (IsPointer<T>::value)		
		printvImp(v, YES);
	else
		printvImp(v, NO);
	*/
}


int main()
{
	int    n = 3;
	printv(n); 
	//printv(&n);
}





