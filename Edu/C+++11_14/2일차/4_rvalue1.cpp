// 4_rvalue1 - 76 ~
#include <iostream>
using namespace std;

// �ӽð�ü ����
class Point
{
	int x, y;
public:
	Point()  { cout << "������" << endl; }
	~Point() { cout << "�Ҹ���" << endl; }
	Point(const Point&) { cout << "���������" << endl; }
};

//Point p1; // ������ü

int main()
{
	cout << "AAA" << endl;
	
	//Point p1; // ���� ��ü - �ڽ��� ������ ���� ���� ���� �ı�

	Point(); // �ӽð�ü - �ڽ��� ���Ե� ������(full expression) ������ �ı��ȴ�.
			 // Ŭ�����̸�() �� �����.
			 // unnamed object(�̸����°�ü)��� ǥ��!
			 // C++ ǥ�ع��� 12.2 �׸񿡼� �ڼ��� ����

	cout << "BBB" << endl;
}




