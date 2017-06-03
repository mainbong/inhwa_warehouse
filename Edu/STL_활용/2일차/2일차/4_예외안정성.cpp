// 4_���ܾ�����
#include "show.h"

// exception safety
// 1. ���� ���� : ���ܰ� ����... int a = 0;
// 2. ���� ���� : ���ܰ� �־ ó���ϸ� ��ü�� ���� ���¸� �����Ѵ�. ��밡��
// 3. �⺻ ���� : ���ܰ� �־ �ڿ� ������ ����. ��ü�� ���´� ���� �ȵ�. ���Ұ�

template<typename T> class stack
{
	T buff[10];
	int index;

public:
	stack() : index(0) {}

	void	push(const T& a)	{ buff[index++] = a; }
	T		pop() 
	{ 
		--index;
		return buff[index]; 
	}
};

int main()
{
	stack<int> s;
	try { s.pop(); }
	catch (int n) {

	}
	// ���α׷��� ��� ���డ��.. �׷��� s ��ü�� ����� �� ������� ?
}