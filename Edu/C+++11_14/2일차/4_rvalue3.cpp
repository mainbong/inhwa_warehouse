// 4_rvalue1 - 76 ~
#include <iostream>
using namespace std;

// 임시객체 개념
class Point
{
	int x, y;
public:
	Point() { cout << "생성자" << endl; }
	~Point() { cout << "소멸자" << endl; }
	Point(const Point&) { cout << "복사생성자" << endl; }
};

// 임시객체와 함수 리턴
Point foo()
{
	// 만들고 리턴하지 말고.. 만들면서 리턴하자!!
	// RVO( return value optimization) 이라는 이름을 가진 기술
	//return Point(); // 리턴용 임시 객체만 만들어 달라.

	// 요즘 컴파일러는 이름있는 객체도 최적화 할수 있습니다.
	// NRVO(Named RVO) - cafe.naver.com/cppmaster C++ Idioms 게시판!
	Point p1;
	return p1; // 리턴용 임시객체를 만들고 - 복사 생성자로 만들게 됩니다
}			   // p1이 파괴 되고
			   // 임시객체를 main에 전달
int main()
{
	Point p;
	cout << "AAA" << endl;

	p = foo();

	cout << "BBB" << endl;
}
// 실행결과 예측해보세요..



