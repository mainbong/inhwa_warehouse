#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// 66 page
int main()
{
	// ���ٴ� �����ϴ� ���
	auto f1 = [](int a, int b) { return a + b; };
	//f1 = [](int a, int b) { return a + b; };// error �� ���ٿ;Ʒ� ���ٴ� �ٸ�
											// Ÿ���̴�. �ٸ�Ÿ�Ժ����� ���Ծȵ�

	int(*f2)(int,int) = [](int a, int b) { return a + b; };

	function<int(int,int)> f3 = [](int a, int b) { return a + b; };
	//f3 = &foo
	// ������ �ζ��� ġȯ�Ǵ� ���� ?
	int n1 = f1(1, 2); // ġȯ ����.!
	int n2 = f2(1, 2); // ġȯ �ȵ�
	int n3 = f3(1, 2); // ġȯ �ȵ�
}


