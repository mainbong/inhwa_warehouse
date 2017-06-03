// 1_스마트포인터5
#include "show.h"
#include <memory>

// 중요한 예제입니다.
// 참조계수 스마트포인터가 상호 참조가 발생하면 메모리가 삭제되지 않습니다.

struct Node
{
	int data;
	//Node* next;
	//shared_ptr<Node> next;

	weak_ptr<Node> next;	// 참조계수를 증가하지 않는 스마트포인터
							// 보통, 별도의 weak용 카운트를 관리한다.
	~Node() { cout << "Node 파괴" << endl; }
};

int main()
{
	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);

	// 아래의 경우 (상호참조가 일어날 경우) 스마트포인터를 사용하면 메모리 누수가 일어난다.
	p1->next = p2;
	p2->next = p1;
}
