// 2_��������3
#include "show.h"

template<typename T, typename Ax = allocateor<T> > class vector
{
	Ax ax; // �޸� �Ҵ�� ��å Ŭ����
public:
	void resize(int sz)
	{
		// �޸� ���Ҵ��� �ʿ��մϴ�.
		// new ? malloc ? calloc ? pool ? system call ?
		T* p = ax.allocate(sz);

		ax.deallocate(p);
	}
};