// 1_위임생성자 - 56 page 항목 2-10
#include <iostream>
using namespace std;

class Point
{
public:
	int x = 0; // C++11 부터는 허용됩니다. field initialize 라는 문법
	int y = 0;

	Point() : Point(0,0) // 위임 생성자 문법 - 생성자에서 다른 생성자 호출하는것
	{
	//	Point(0, 0); // 다른 생성자 호출이 아니라 임시객체를 만드는 표현입니다.
					// 다음시간에 임시객체에 대해 자세히...
	}
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p;
	cout << p.x << endl;
}





