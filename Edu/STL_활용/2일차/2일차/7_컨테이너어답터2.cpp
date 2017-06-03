// 7_컨테이너어답터2
#include "show.h"

// STL에는 3개의 컨테이너 어답터가 있습니다. : stack, queue, priority_queue
#include <stack>
#include <queue>

int main()
{
	// 다음 중 에러는 ?
	// stack 은 한쪽만 뚫리면 OK
	stack<int, vector<int>> s1;
	stack<int, list<int>> s2;

	// queue 는 양쪽이 뚫려야 OK
	queue<int, vector<int>> q1; // error , vector 는 한쪽만 뚫림
	queue<int, list<int>> q2;

	q1.push(10);	// 내부 컨테이너에 뒤에 넣기
	//q1.pop();		// 앞으로 제거.. vector 사용 시 여기서 error

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(10);
	pq.push(30);
	pq.push(5);

	cout << pq.top() << endl; // 우선순위가 제일 높은 요소가 나온다.
								// 5 나오게 코드를 수정해보세요.
}