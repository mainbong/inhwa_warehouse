#include <iostream>
using namespace std;

// �ӽð�ü�� lvalue!!

struct Point { int x, y; };

Point p = { 1, 2};

//Point foo()  : �� ���� : �ӽð�ü ����, �Լ�ȣ���� lvalue�� �ɼ� ����.
Point& foo()  // �������� : �ӽð�ü�� ������ ����, �Լ� ȣ���� lvalue �� �ɼ��ִ�.
{
	return p; // �̼��� p�� ���纻�� �ӽð�ü�� ���ϵȴ�.
}  

int main()
{
	foo().x = 10; // VC++������ ������ ������ gcc, clang ������ ������ �����߻�
				  // �ӽð�ü�� =�� ���ʿ� �ü� ����.(lvalue�� �ɼ� ����)

	cout << p.x << endl; // 1
}





