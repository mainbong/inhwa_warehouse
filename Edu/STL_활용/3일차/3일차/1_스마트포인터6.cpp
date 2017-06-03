#include "show.h"
#include <memory>

int main()
{
	int* p = 0;
	weak_ptr<int> wp;
	{
		shared_ptr<int> sp(new int);
		
		cout << sp.use_count() << endl; // 1

		p = sp.get(); // 스마트 포인터 안에 있는 진짜 포인터 꺼내기
		wp = sp;

		cout << sp.use_count() << endl; // 1
	} // 자원파괴되었다.

	// 진짜 포인터 사용 시 자원이 파괴되었는지 조사할 방법이 없다.
	cout << p << endl;

	// weak_ptr 사용 시 자원이 파괴 되었는지 알 수 있다.
	cout << wp.use_count() << endl;	// shared_ptr의 카운트 출력

	// 아래처럼 하면 절대 안됩니다.
	// 다른 스레드에서 shared_ptr<> 을 가지고 있었다면
	// if()문 조사 후 wp 사용전에 파괴될 수 있습니다.
	/*
	if (wp.use_count() > 0)
	{
		// 자원이 살아 있으므로 사용?

		wp->멤버함수 호출();
	}*/

	// weak_ptr로 shared_ptr<>을 다시 생성해야 합니다.
	shared_ptr<int> sp2 = wp.lock();	// 안드로이드 wp.promote()
	if (sp2 == nullptr)
		cout << "자원 파괴 됨" << endl;
	else
		cout << "자원 사용 가능" << endl;
}