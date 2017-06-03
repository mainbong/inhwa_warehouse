// 4_initializer_list2
#include <iostream>
#include <vector>
using namespace std;

// �����ڿ� initializer_list - 33 page

class Point
{
	int x, y;
public:
	Point()				{ cout << "Point()" << endl; }
	Point(int a, int b) { cout << "Point(int,int)" << endl; }
	Point(initializer_list<int> e) { cout << "Point(initializer_list)" << endl; }
};
int main()
{
	// ��� �Լ��� ȣ������ ������ ������
	Point p1;			// 1
	Point p2(1, 1);		// 2�� ������ error
	
	Point p3{1, 1 };    // 3�� ������ 2�� ȣ��
//	Point p4(1, 2, 3);  // error ?
	Point p5{ 1,2,3 };  // 3�� ������ error

	// �ٽ� ��ü �ʱ�ȭ��  {} ����ؼ� ���� ������ ������ �ִ�.

	// 1 ~ 10 ���� �ʱ�ȭ�� vector�����
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };//ok.. ���� ����
}

