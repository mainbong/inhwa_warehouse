// 7_�����̳ʾ����2
#include "show.h"

// STL���� 3���� �����̳� ����Ͱ� �ֽ��ϴ�. : stack, queue, priority_queue
#include <stack>
#include <queue>

int main()
{
	// ���� �� ������ ?
	// stack �� ���ʸ� �ո��� OK
	stack<int, vector<int>> s1;
	stack<int, list<int>> s2;

	// queue �� ������ �շ��� OK
	queue<int, vector<int>> q1; // error , vector �� ���ʸ� �ո�
	queue<int, list<int>> q2;

	q1.push(10);	// ���� �����̳ʿ� �ڿ� �ֱ�
	//q1.pop();		// ������ ����.. vector ��� �� ���⼭ error

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(10);
	pq.push(30);
	pq.push(5);

	cout << pq.top() << endl; // �켱������ ���� ���� ��Ұ� ���´�.
								// 5 ������ �ڵ带 �����غ�����.
}