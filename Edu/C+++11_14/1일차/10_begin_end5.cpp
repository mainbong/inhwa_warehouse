#include <iostream>
using namespace std;

// ranged-for�� ���� - 26 page
struct Point3D
{
	int x, y, z;
};
// ����� ���� ���հ�ü�� ranged_for�� �����Ϸ��� begin(), end()�� �ʿ��մϴ�.
const int* begin(const Point3D& p) { return &(p.x); }
const int* end(const Point3D& p)   { return &(p.z) + 1; } // past the end : �������������


int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (auto n : x) // �� ������ ������ ����� ?
		cout << n << endl;

	// �� ������ ������ �ϸ� �Ʒ� �ڵ尡 �˴ϴ�.
	/*
	for (auto p = begin(x); p != end(x); ++p)
	{
		auto n = *p;
		
		// ���� ����� �ڵ�
		cout << n << endl;
	}
	*/

	Point3D p3d;

	for (auto n2 : p3d) // �ɱ�� ?
	{
		cout << n2 << endl;
	}
}





