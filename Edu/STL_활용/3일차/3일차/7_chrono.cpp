// 7_chrono
#include "show.h"
#include <chrono>
using namespace std::chrono;	// �ð�, Ÿ�̸� ���� ���� C++ ǥ�� ���̺귯��
								// C++11 ���� �߰�

/*
template<int N1, int N2> struct ratio
{
	static const int num = N1; // ����
	static const int den = N2; // �и�
};
*/
int main()
{
	ratio<1, 2> r1; // 1/2
	cout << r1.num << endl;
	cout << r1.den << endl;

	ratio<5, 10> r2; // 1/2
	cout << r2.num << endl;
	cout << r2.den << endl;

	//typedef ratio<1, 1000> milli;
	milli m;
	cout << m.num << endl;
	cout << m.den << endl;
}