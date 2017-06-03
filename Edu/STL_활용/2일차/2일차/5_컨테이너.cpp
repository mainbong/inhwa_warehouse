//3_컨테이너
#include "show.h"
#include <stack>
// 36page 그림 참고
// 1.  sequence container : vector, list, deque

int main()
{
	vector<int> v;
	v.push_back(10);

	int n1 = v.back(); // 리턴만. 제거 안됨.
//	int n2 = v.pop_back(); // 제거만, 리턴 안됨. error. void 리턴.

	stack<int> s;
	s.push(10);
	s.push(20);

	cout << s.top() << endl; // 20
	s.pop(); // 제거만. 리턴안함.
	cout << s.top() << endl;
}