// 9_static_assert - 12 page �׸� 2-1
#include <iostream>
#include <cassert>
using namespace std;

void foo(int age)
{
	// �Լ��� ���ڴ� �ٷ� ������� ����
	// ������ ��ȿ���� ���� Ȯ���ϴ� ���� ����.
	assert(age > 0);  // ���� C�� assert() : runtime �� ����


	//C++11 ������ �ð� assert ����
	static_assert(sizeof(int) >= 8, "int�� 8����Ʈ �̻��� �ý��۸� �����ϰ���");


	char* p = new char[age];
}

int main()
{
	foo(-10);
}

