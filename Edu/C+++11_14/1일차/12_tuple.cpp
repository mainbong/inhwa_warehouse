// 12_tuple - �������� ���ø��� ���� ���� - 45page
#include <iostream>
using namespace std;

#include <tuple>

int main()
{
//	int x[10];
//	vector<int> v(10);

	// ���� �ٸ� Ÿ�� �������� �����ϴ� �����̳�.!
	tuple<int, double, char> t3(3, 3.2, 'a');

	// Ʃ�ÿ��� ��� ������
	cout << get<1>(t3) << endl; // 3.2
}



