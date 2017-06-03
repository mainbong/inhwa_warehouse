// 3_uniform_initialize - 29page
#include <iostream>
using namespace std;

struct Point { int x, y; };
class Complex
{
	int re, im;
public:
	Complex(int a, int b) : re(a), im(b) {}
};
int main()
{
	// ���� C++���� ��ü�� �ʱ�ȭ �ϴ� ���.
	/*
	int n1 = 0;
	int n2(0);

	int x[10] = { 1,2 };
	Point p = { 1,1 };
	Complex c(0, 0);
	*/
	//--------------------------------
	// C++11 �ʱ�ȭ ��� => {} ���
	// "Uniform Initialize" ��� ����.
	int n1 = { 0 };
	int n2{ 0 };

	int x[10]{ 1,2 };
	Point p { 1,1 };
	Complex c{ 0, 0 };

	int n3 = 3.4; // ok.. ������ ����
//	int n4{ 3.4 };// error. prevent narrow


//	char c3{ 300 }; // error. 300�� 1byte�� ǥ�� �ȵ�..

}




