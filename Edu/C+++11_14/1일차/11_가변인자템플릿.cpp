// 11_가변인자템플릿 - 40 page ~ 항목2-8. 어려운 주제 입니다.

#include <iostream>
using namespace std;

// 가변인자 클래스 템플릿
template<typename ... Types> class Test 
{
};
// 가변인자 함수 템플릿
template<typename ... Types> void foo(Types ... args)
{

}

int main()
{
	foo();
	foo(1);
	foo(1, 2.2);

	Test<int, double, char> t1;
}






