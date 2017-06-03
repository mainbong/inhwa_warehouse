// 2_�����������Ʈ������2
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
	// �������� ���� - ���ø� ���ڷ� ����
	// ���� : �����ڸ� ������ ������ �ʿ� ����, �ζ��� ġȯ�ȴ�.
	// ���� : �����ڰ� �ٸ��� �ٸ� Ÿ���� �ȴ�. ���� �����̳ʿ� ���� �ȵȴ�.
	unique_ptr<int> p1(new int); 
	unique_ptr<int[]> p2(new int[10]);
	unique_ptr<int, Freer> p2((int*)malloc(100));

	//shared_ptr<int> p2((int*)malloc(100), foo); // �Ҹ��ڴ� ������ü���� ��������� �Բ� �����Ǹ� �Ҹ�ÿ� ȣ��ȴ�.
												// �׷��� unique ptr �� ������ü�� ����! �׷��ٸ� ���!?
}