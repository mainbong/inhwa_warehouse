#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// 람다와 함수 인자 - 66 page 아래 코드
//void sort( int(*p)(int,int) ) // 가능하지만 인라인 치환 안됨

//void sort(function<int(int,int)> p ) // 가능하지만 인라인 치환 안됨

//void sort( auto p) //될까요 ?? auto는 함수 인자타입이 될수 없다!! error

// 결론 : 람다표현식을 인자로 받으려면 템플릿을 사용하자!
// "함수인자의 T는 지역변수의 auto와 유사한 개념입니다.!"- 다음시간
template<typename T> void sort( T p) // ok.. 인라인 치환도 된다.!!
{
	cout << p(1, 2) << endl;
}

int main()
{
	sort( [](int a, int b) {return  a + b; } );
}


