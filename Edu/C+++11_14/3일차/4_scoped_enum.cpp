// 4_scoped_enum - 35page
#include <iostream>
using namespace std;

// C�� C++98/03�� enum
// unscoped enum
enum Color { red = 0, green, blue};

// C++11 scoped enum
//enum class Shape { rect = 0, circle };

// type�� �����Ҽ� �ֽ��ϴ�
enum class Shape : char { rect = 0, circle };

int main()
{
//	int n1 = rect; // error. rect�� Shape�ȿ� �ִ�
//	int n2 = Shape::rect;// error, Rect�� Shape Ÿ���̴�.

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