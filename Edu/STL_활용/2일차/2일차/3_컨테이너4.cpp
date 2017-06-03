//3_컨테이너4
#include "show.h"

// 사용자 정의 타입과 STL 컨테이너.
// 1. 디폴트 생성자가 있는 것이 좋다. 없는 경우 main()참고.

class People
{
	string name;
	int age;
public:
	People(string n, int a) : name(n), age(a) {}
};

int main()
{
	vector<People> v(10, People("unknown", 0));
	v.resize(20, People("unknown", 0)); // resize(20) 해보세요

	// 2. 요소 넣기
	People p1("park", 20);
	v.push_back(p1); // 이것은 이 블록이 끝날때까지 p1 이 메모리에 유지, 안좋음.

	// 임시 객체를 사용해서 넣기.
	v.push_back(People("kim", 10));

	// 생성자 인자만 전달해서 People 자체를 vector 가 만들게 하자.
	v.emplace_back("lee", 30); // C++11 에 새로 나온 함수.
}