//3_�����̳�
#include "show.h"
#include <stack>
// 36page �׸� ����
// 1.  sequence container : vector, list, deque

int main()
{
	vector<int> v;
	v.push_back(10);

	int n1 = v.back(); // ���ϸ�. ���� �ȵ�.
//	int n2 = v.pop_back(); // ���Ÿ�, ���� �ȵ�. error. void ����.

	stack<int> s;
	s.push(10);
	s.push(20);

	cout << s.top() << endl; // 20
	s.pop(); // ���Ÿ�. ���Ͼ���.
	cout << s.top() << endl;
}