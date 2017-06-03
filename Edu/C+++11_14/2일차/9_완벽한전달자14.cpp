// 9_�Ϻ���������14
#include <iostream>
using namespace std;

// �̱��� : ���� �Ѱ��� ��ü�� ����� Ŭ����
// CRTP : �θ� ���ø��ε� �ڽ��� ��ӹ����鼭 �ڽ��� �̸��� �θ� 
//		  ���ø����ڷ� �˷��ִ� ��� - �ȵ���̵� �̱����� ����!!
template<typename T> class Singleton
{
public:
	template<typename ... Types>
	static T& getInstance(Types&& ... args)
	{
		static T s(forward<Types>(args)...);
		return s;
	}
};
// Cursor�� �̱������� �ϰ� �ͽ��ϴ�.
class Cursor : public Singleton<Cursor>
{
public:
	Cursor(int a, int b) {}
};

int main()
{
	Cursor& s = Cursor::getInstance(10, 20);
}





