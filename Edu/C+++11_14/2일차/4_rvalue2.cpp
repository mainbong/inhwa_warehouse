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

void foo(Point p) { cout << "foo" << endl; }

int main()
{
	cout << "AAA" << endl;

	// 함수인자와 임시객체
//	Point p;
//	foo(p);

	foo( Point() ); // 단순히 인자로만 사용할 객체는 임시객체로 만들기도 한다.


	cout << "BBB" << endl;
}




