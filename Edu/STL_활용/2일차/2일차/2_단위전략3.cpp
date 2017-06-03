// 2_단위전략3
#include "show.h"

template<typename T, typename Ax = allocateor<T> > class vector
{
	Ax ax; // 메모리 할당용 정책 클래스
public:
	void resize(int sz)
	{
		// 메모리 재할당이 필요합니다.
		// new ? malloc ? calloc ? pool ? system call ?
		T* p = ax.allocate(sz);

		ax.deallocate(p);
	}
};