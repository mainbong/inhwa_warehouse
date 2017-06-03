#include "show.h"
#include <memory>

int main()
{
	int* p = 0;
	weak_ptr<int> wp;
	{
		shared_ptr<int> sp(new int);
		
		cout << sp.use_count() << endl; // 1

		p = sp.get(); // ����Ʈ ������ �ȿ� �ִ� ��¥ ������ ������
		wp = sp;

		cout << sp.use_count() << endl; // 1
	} // �ڿ��ı��Ǿ���.

	// ��¥ ������ ��� �� �ڿ��� �ı��Ǿ����� ������ ����� ����.
	cout << p << endl;

	// weak_ptr ��� �� �ڿ��� �ı� �Ǿ����� �� �� �ִ�.
	cout << wp.use_count() << endl;	// shared_ptr�� ī��Ʈ ���

	// �Ʒ�ó�� �ϸ� ���� �ȵ˴ϴ�.
	// �ٸ� �����忡�� shared_ptr<> �� ������ �־��ٸ�
	// if()�� ���� �� wp ������� �ı��� �� �ֽ��ϴ�.
	/*
	if (wp.use_count() > 0)
	{
		// �ڿ��� ��� �����Ƿ� ���?

		wp->����Լ� ȣ��();
	}*/

	// weak_ptr�� shared_ptr<>�� �ٽ� �����ؾ� �մϴ�.
	shared_ptr<int> sp2 = wp.lock();	// �ȵ���̵� wp.promote()
	if (sp2 == nullptr)
		cout << "�ڿ� �ı� ��" << endl;
	else
		cout << "�ڿ� ��� ����" << endl;
}