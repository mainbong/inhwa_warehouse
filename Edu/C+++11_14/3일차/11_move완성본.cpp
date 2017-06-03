//11_move완성본
#include <iostream>
using namespace std;

class Cat
{
public:
	Cat() = default;
	Cat(const Cat& c) { cout << "복사" << endl; }
	Cat(Cat&& c)      { cout << "이동" << endl; }
};
Cat foo() { return Cat(); }

// 어제 소스중 move3번에서 move 함수만 복사해오세요.. 이름을 xmove로 변경하세요
// 1. rvalue와 lvalue 모두 move를 가능하게 하고 싶었다...
//    universal reference를 사용하자.

// 2. 인자로 lvalue인 c1이 오면 T : int&

template<typename T> typename remove_reference<T>::type&& xmove(T&& a) // int& &&
{
	//return static_cast<T&&>(a); // static_cast<int& &&>(a)

	return static_cast<typename remove_reference<T>::type&&>(a);
}

int main()
{
	Cat c1;
	Cat c2 = move(c1);

	Cat c3 = xmove(foo()); // 되는게 좋을까요 ? 안되는게 좋을까요 ?
							// 임시객체도 자원을 전달하고 사라질수 있는게 좋다
}










