// 1_����Ʈ������5
#include "show.h"
#include <memory>

// �߿��� �����Դϴ�.
// ������� ����Ʈ�����Ͱ� ��ȣ ������ �߻��ϸ� �޸𸮰� �������� �ʽ��ϴ�.

struct Node
{
	int data;
	//Node* next;
	//shared_ptr<Node> next;

	weak_ptr<Node> next;	// ��������� �������� �ʴ� ����Ʈ������
							// ����, ������ weak�� ī��Ʈ�� �����Ѵ�.
	~Node() { cout << "Node �ı�" << endl; }
};

int main()
{
	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);

	// �Ʒ��� ��� (��ȣ������ �Ͼ ���) ����Ʈ�����͸� ����ϸ� �޸� ������ �Ͼ��.
	p1->next = p2;
	p2->next = p1;
}
