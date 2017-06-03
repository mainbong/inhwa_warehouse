// 4_scoped_enum - 35page
#include <iostream>
using namespace std;

// C와 C++98/03의 enum
// unscoped enum
enum Color { red = 0, green, blue};

// C++11 scoped enum
//enum class Shape { rect = 0, circle };

// type을 지정할수 있습니다
enum class Shape : char { rect = 0, circle };

int main()
{
//	int n1 = rect; // error. rect는 Shape안에 있다
//	int n2 = Shape::rect;// error, Rect는 Shape 타입이다.

	Shape n3 = Shape::rect;// ok..

	int n4 = static_cast<int>(Shape::rect); // ok
}



/*
int main()
{
	int a = Color::red; // ok
	int n = red; // ok..!!
	int red = 20;
	int n2 = red; // ???? 0 ? 20
}
*/