//11_move�ϼ���
#include <iostream>
using namespace std;

class Cat
{
public:
	Cat() = default;
	Cat(const Cat& c) { cout << "����" << endl; }
	Cat(Cat&& c)      { cout << "�̵�" << endl; }
};
Cat foo() { return Cat(); }

// ���� �ҽ��� move3������ move �Լ��� �����ؿ�����.. �̸��� xmove�� �����ϼ���
// 1. rvalue�� lvalue ��� move�� �����ϰ� �ϰ� �;���...
//    universal reference�� �������.

// 2. ���ڷ� lvalue�� c1�� ���� T : int&

template<typename T> typename remove_reference<T>::type&& xmove(T&& a) // int& &&
{
	//return static_cast<T&&>(a); // static_cast<int& &&>(a)

	return static_cast<typename remove_reference<T>::type&&>(a);
}

int main()
{
	Cat c1;
	Cat c2 = move(c1);

	Cat c3 = xmove(foo()); // �Ǵ°� ������� ? �ȵǴ°� ������� ?
							// �ӽð�ü�� �ڿ��� �����ϰ� ������� �ִ°� ����
}










