// 1_���ӻ����� - 56 page �׸� 2-10
#include <iostream>
using namespace std;

class Point
{
public:
	int x = 0; // C++11 ���ʹ� ���˴ϴ�. field initialize ��� ����
	int y = 0;

	Point() : Point(0,0) // ���� ������ ���� - �����ڿ��� �ٸ� ������ ȣ���ϴ°�
	{
	//	Point(0, 0); // �ٸ� ������ ȣ���� �ƴ϶� �ӽð�ü�� ����� ǥ���Դϴ�.
					// �����ð��� �ӽð�ü�� ���� �ڼ���...
	}
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p;
	cout << p.x << endl;
}





