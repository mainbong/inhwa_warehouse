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

void foo(Point p) { cout << "foo" << endl; }

int main()
{
	cout << "AAA" << endl;

	// �Լ����ڿ� �ӽð�ü
//	Point p;
//	foo(p);

	foo( Point() ); // �ܼ��� ���ڷθ� ����� ��ü�� �ӽð�ü�� ����⵵ �Ѵ�.


	cout << "BBB" << endl;
}




