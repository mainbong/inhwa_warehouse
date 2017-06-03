#include "show.h"

// 반복자의 분류(category)

// one pass 만 보장 ( 처음부터 끝까지 뽑았으면 다음에 다시 처음으로 돌아가는걸 보장할 수 없다 )
// 1. 입력 반복자(input iterator) : =*p, ++
// 2. 출력 반복자(output iterator) : *p=, ++

// multi pass 보장.
// 3. 전진형 반복자(forward iterator) : 입출력, ++					=> 싱글 리스트
// 4. 양방향 반복자(bidirectional iterator) : 입출력, ++, --				=> 더블 리스트
// 5. 임의접근 반복자(random access iterator) : 입출력, ++, --, [], +, - => 연속된 메모리 유사 
//								( vector 는 연속, deque 는 연속되지 않지만 임의 접근 반복자를 가진다 )

// 6. C++11에서 반복자의 분류를 추가합니다.
//	continuous 반복자 : 연속된 메모리 보장

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* p = find(x, x + 10, 5); // 1,2 번째 인자는 반복자 입니다.
								// 최소 요구 조건은 5가지 중 무엇일까요 ?
								// 입력 반복자

	reverse(x, x + 10); // 최소조건 ?
						// 양방향 반복자, -- 가 필요하다.

	sort(x, x + 10); // 퀵소트 입니다. 최소조건 ?
					 // 임의 접근 반복자..

	//------------------------------------------------
	//slist<int> s1;
	//reverse(s1.begin(), s1.end()); // ?

	list<int> s2 = { 1,2,3 };
	sort(s2.begin(), s2.end()); // 임의 접근이 필요하다. s2의 반복자는 양방향 반복자이다.

	s2.sort(); // 퀵이 아닌 다른 알고리즘(selection 또는 bubble)
	
	vector<int> v = { 1,2,3 };
	//v.sort(); // 이 멤버 함수가 있을까요 ? 벡터는 임의접근이라 일반함수 sort 사용가능, 멤버 함수에 없다. vector 는 
}