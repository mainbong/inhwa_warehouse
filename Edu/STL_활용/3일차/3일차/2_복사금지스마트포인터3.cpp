#include "show.h"
#include <memory>

int main()
{
	shared_ptr<int> sp1(new int);
	unique_ptr<int> up1(new int);

	// 다음중 에러를 모두 골라 보세요.
	shared_ptr<int> sp2 = up1;			// error , 독점권 포기없이 공유권을 주겠다 ? 놉!
	unique_ptr<int> up2 = sp1;			// error

	shared_ptr<int> sp3 = move(up1);	// 독점권을 포기하겠다. 그럼 문제될건 없지!
	unique_ptr<int> up3 = move(sp1);	// 공유권을 다 넘기지도 않고 나만 준다고 독점할 순 없지!
}