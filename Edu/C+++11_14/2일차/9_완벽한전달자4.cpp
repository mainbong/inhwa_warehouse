#include <iostream>
using namespace std;

// �ذ�å 2. �̵� ������ ���� �����

// ���� �ƴ� ������ �̵��ϴ� ����!!
template<typename T> class xreference_wrapper
{
	// �ᱹ ������ �ٸ� ������ �����Ѿ� �մϴ�... �������ʿ�
	T* obj;
public:
	xreference_wrapper(T& r) : obj(&r) {}

	// C++�� �Ϲ� ������ �Ͻ��� ��ȯ �����ϰ� �Ѵ�.
	operator T&() { return *obj; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;
	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;
	r1 = r2; // ???

	int& r3 = r1; // r1�� ��¥ �����ε� ��ȯ�˴ϴ�.

	// ��� ������ ������ 
	cout << n1 << endl; // 10
	cout << n2 << endl; // 20
	cout << r1 << endl; // 20
	cout << r2 << endl; // 20
						// C++ �����Ϸ��� r1 ��ü�� cout���� ��� �Ҽ� ������
						// ��� ������ Ÿ������ ��ȯ�� ���������� �����Ѵ�.
						// int&�� ��ȯ �����ϹǷ� ��ȯ�ؼ� ��µȴ�.
}





