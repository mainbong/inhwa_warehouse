// 4_rvalue1 - 76 ~
#include <iostream>
using namespace std;

// �ӽð�ü ����
class Point
{
	int x, y;
public:
	Point() { cout << "������" << endl; }
	~Point() { cout << "�Ҹ���" << endl; }
	Point(const Point&) { cout << "���������" << endl; }
};

// �ӽð�ü�� �Լ� ����
Point foo()
{
	// ����� �������� ����.. ����鼭 ��������!!
	// RVO( return value optimization) �̶�� �̸��� ���� ���
	//return Point(); // ���Ͽ� �ӽ� ��ü�� ����� �޶�.

	// ���� �����Ϸ��� �̸��ִ� ��ü�� ����ȭ �Ҽ� �ֽ��ϴ�.
	// NRVO(Named RVO) - cafe.naver.com/cppmaster C++ Idioms �Խ���!
	Point p1;
	return p1; // ���Ͽ� �ӽð�ü�� ����� - ���� �����ڷ� ����� �˴ϴ�
}			   // p1�� �ı� �ǰ�
			   // �ӽð�ü�� main�� ����
int main()
{
	Point p;
	cout << "AAA" << endl;

	p = foo();

	cout << "BBB" << endl;
}
// ������ �����غ�����..



