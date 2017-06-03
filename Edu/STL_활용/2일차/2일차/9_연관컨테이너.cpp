// 9_연관컨테이너

#include "show.h"
#include <set>

int main()
{
	typedef set<int, greater<int>> SET;
	SET s;	// RB(red black) Tree
	s.insert(10);
	s.insert(30);
	s.insert(20);
	s.insert(20);	
	s.insert(40);

	pair<SET::iterator, bool> ret =s.insert(20); // 요놈의 리턴값은 pair인데, first 는 반복자, second 는 성공여부이다.
	if (!ret.second)
	{
		cout << "기존에 요소가 있습니다." << endl;
	}

	// 아래 코드를 평가해보세요
	//SET::iterator p2 = find(s.begin(), s.end(), 20); // 찾을 수는 있는데 RB-Tree 만들어놓고 선형검색하고 자빠졌네.
													// 트리는 binary 서치가 갑이제.
	auto p2 = s.find(20);	// 이게 제대로 바이너리 써치지.
	cout << *p2 <<"을 찾았습니다."<< endl;
	
	//	set<int>::iterator p= s.begin(); // 가장 왼쪽 노드..
	SET::iterator p = s.begin(); // 다적으면 귀찮으니께.. 근데 auto가 짱
	while (p != s.end())
	{
		cout << *p << endl;
		++p; // inorder 순회...
	}
}