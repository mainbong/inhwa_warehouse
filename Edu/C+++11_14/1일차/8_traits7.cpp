#include <iostream>
using namespace std;

// 아래 헤더에 100여개의 traits(메타함수)가 있습니다.
#include <type_traits>

template<typename T> void fooImp(const T& a, true_type) 
{ 
	cout << "fooImp true_type" << endl;
	*a = 10; 
}

template<typename T> void fooImp(const T& a, false_type)
{
	//*a = 10; 
	cout << "fooImp false_type" << endl;
}

template<typename T> void foo(const T& a)
{
	// a이 특질에 따라서 알고리즘을 바꾸고 싶다면
	// 1. value를 if문으로 조사한다.
	//	  단점, a가 포인터라도 *a 표현을 사용할수 없다.
	if (is_pointer<T>::value)
		cout << "포인터 일때 알고리즘" << endl; // *a
	else
		cout << "포인터 아닐때 알고리즘" << endl;

	// 2. *a 등의 표현이 필요하며 - 함수 오버로딩 사용
	fooImp( a, is_pointer<T>() );
}


int main()
{
	int n = 10;
	foo(&n);
}






