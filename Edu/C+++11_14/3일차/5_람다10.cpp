#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// ���ٿ� ���� Ÿ�� - 67 page
int main()
{
	auto f1 = [](int a, int b) { return a + b; };

	// trailing return, suffix return type syntax
	auto f2 = [](int a, int b) -> int { return a + b; };


	auto f3 = [](int a, int b) { if (a == 1) return a;
										else return b; };

	// 2���̻��� ���Ϲ��� �ٸ� Ÿ���� �����ϸ� �ݵ�� trailing return�� ǥ���ؾ��Ѵ�.
	auto f4 = [](int a, int b) -> double { if (a == 1) return a;
											else return 3.4; };
}


