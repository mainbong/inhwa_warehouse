// 11_�����������ø� - 40 page ~ �׸�2-8. ����� ���� �Դϴ�.

#include <iostream>
using namespace std;

// �������� Ŭ���� ���ø�
template<typename ... Types> class Test 
{
};
// �������� �Լ� ���ø�
template<typename ... Types> void foo(Types ... args)
{

}

int main()
{
	foo();
	foo(1);
	foo(1, 2.2);

	Test<int, double, char> t1;
}






