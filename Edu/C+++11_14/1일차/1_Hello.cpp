// 1_Hello.cpp
#include <iostream>
#include <complex>
#include <chrono>
using namespace std;
using namespace std::chrono;

// C++11 �̸� ����.! - 3 page 2��
int main()
{
	int n1 = 0b10;      // Binary Literal
	int n2 = 1'000'000; // Digit Separator

	cout << n1 << endl; // 2
	cout << n2 << endl;

	double x[5] = { 1,2,3,4,5 };

	auto n3 = x[0]; // �����Ϸ��� �캯�� Ÿ���� �����ؼ� �º��� �����ش޶�

	decltype(n3) n4 = n3; // n3�� ���� Ÿ���� ���� n4�� ����� �޶�
						  // gcc�� typeof()����.


	float f = 3.4f; // f : float�� ��Ÿ���� ���̻�..
					// f, l, s ��

	// user define literal ����
	minutes m2 = 3min;

	cout << m2.count() << endl;


	complex<int> c1(3);

	cout << c1 << endl; // 3 + 0i


	complex<int> c2(3i); // i�� ������ϴ�.

	cout << c2 << endl; // 0 + 3i

	
	for (int i = 0; i < 5; i++)
	{
		double d = x[i];
	}

	// C++11 ranged for
	for ( auto d : x)  // C# java �� foreach()����.
	{
		cout << d << endl;
	}
}










// ������  + ���� : Ctrl + F5
// �����ϸ� : Ctrl + Shift + B







