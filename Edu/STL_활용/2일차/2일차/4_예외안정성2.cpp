// 4_���ܾ�����
#include "show.h"

template<typename T> class stack
{
	T buff[10];
	int index;

public:
	stack() : index(0) {}

	void	push(const T& a) { buff[index++] = a; }
	T		pop() 
	{
		if (index < 1) throw 1;
		--index;
		return buff[index]; 
	}
};

class People
{

};

int main()
{
	stack<People> s;
	People p;
	s.push(p);

	try 
	{ 
		//People p2 = s.pop();	// 1. pop() ���� - �ƹ� ���� ����
								// 2. People ���� ������ ����
								// - ���⼭ ���ܰ� ������ ? ���!! ���� ���ſ� �̱⸦ ���ÿ� �ϸ� �ȵǰڴ�...
		People p2 = s.top(); // ���� ������ ���ܰ� �־
							 // ��ü�� stack �� ���� �ֽ��ϴ�.
	}
	catch (... n) {

	}
	// ���α׷��� ��� ���డ��.. �׷��� s ��ü�� ����� �� ������� ?
}