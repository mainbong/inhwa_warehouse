// 3_hash
#include "show.h"
#include <set> // RB Tree
#include <unordered_set> // hash

int main()
{
	unordered_set<int> s; // set<> 과 사용법은 거의 유사.
	s.insert(10);
	s.insert(30);
	s.insert(15);
	s.insert(20);

	auto ret = s.insert(20);

	if (ret.second == false)
		cout << "실패" << endl;

	// s 에서 30을 찾아서 출력해보세요.
	unordered_set<int>::iterator p = s.find(30); // hash함수를 사용해서 검색
	cout << *p << endl; // 30
}