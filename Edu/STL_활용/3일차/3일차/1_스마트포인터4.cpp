// TODO : HAVE TO BE REFREASH WITH cafe.naver.com/cppmaster
// 2_����Ʈ������4
#include "show.h"
#include <memory>

void foo(int* p)
{
	cout << "foo" << endl;
	delete[] p;
}

struct ArrayDeleter
{
	void operator()(int *p) { delete[] p; }
};

int main()
{
	// �������� ����.
	shared_ptr<int> p1(new int);
	shared_ptr<int> p2(new int[10], foo);
	shared_ptr<int> p3(new int[10], ArrayDeleter()); // �ӽð�ü�� ����
	shared_ptr<int> p4(new int[10], [](int *p) { delete[] p; });
}