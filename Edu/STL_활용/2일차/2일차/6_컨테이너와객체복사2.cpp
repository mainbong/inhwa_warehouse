#define _CRT_SECURE_NO_WARNINGS
// 6_컨테이너와객체복사
#include "show.h"

class People
{
	char* name;
public:
	People(const char* n = "AA")
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~People() { delete[] name; }

	People(const People& p)
	{
		cout << "복사 생성자 호출" << endl;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
	
	// C++11의 Move 생성자 - 소유권 이전을 사용한 기술
	// move 생성자 만들때는 예외가 없다고 표시하는 것이 좋습니다.
	// move 중 예외가 발생하면 강력보장이 안되기 때문에, 예외가 없음을 보장해줘야 사용 가능하다.
	People(People&& p) noexcept
	{
		cout << "move 생성자 호출" << endl;

		name = p.name;	// 얕은 복사 후
		p.name = 0;		// 원본을 0으로
	}
	
};

int main()
{	
	//People p1("AA");
	//People p2 = p1; // 복사 생성자
	//People p3 = move(p1); // move생성자 호츌. 없으면 복사 생성자 호출.

	vector<People> v(10);
	v.resize(20); // 이순간을 생각해보세요.
	// 이순간 기존 AAA피플들은 새로잡히는 20개의 메모리에 깊은 복사가 일어남.
	// 그리고 기존 AAA피플들은 모두 제거되는데, 이는 매우 비효율적. 제거시킬것이라면 얕은 복사로 포인터만 오는게 좋지 않겠나.
}