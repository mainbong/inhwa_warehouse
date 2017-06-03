// 2_복사금지스마트포인터2
#include "show.h"
#include <memory>

struct Freer
{
	inline void operator()(void* p)
	{
		cout << "free" << endl;
		free(p);
	}
};

int main()
{
	// 삭제자의 전달 - 템플릿 인자로 전달
	// 장점 : 삭제자를 별도로 보관할 필요 없고, 인라인 치환된다.
	// 단점 : 삭제자가 다르면 다른 타입이 된다. 같읕 컨테이너에 보관 안된다.
	unique_ptr<int> p1(new int); 
	unique_ptr<int[]> p2(new int[10]);
	unique_ptr<int, Freer> p2((int*)malloc(100));

	//shared_ptr<int> p2((int*)malloc(100), foo); // 소멸자는 관리객체에서 참조계수와 함께 관리되며 소멸시에 호출된다.
												// 그러나 unique ptr 은 관리객체가 없다! 그렇다면 어떻게!?
}