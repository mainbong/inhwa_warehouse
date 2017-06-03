//4_알고리즘
#include "show.h"

// 핵심 1: remove()등의 알고리즘은 컨테이너 자체를 줄이지 않습니다. 리턴값으로 유효범위를 알려줌.
int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,3,10 };

	// remove 는 배열, vector, list 모두에게 사용될 수 있다.
	// 따라서 이 함수가 컨테이너의사이즈를 줄여주진 않고 항목제거 후 땡겨주는 역활을 한다.
	vector<int>::iterator p = remove(v.begin(), v.end(), 3);
	cout << *p << endl; // 3을 가리킨다. 맨 마지막의 다음 부분. 제거 후 유효한 값 다음을 가리키는 것이다.
	v.erase(p, v.end());
	show(v);
}