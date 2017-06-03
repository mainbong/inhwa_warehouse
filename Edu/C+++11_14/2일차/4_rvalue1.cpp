// 4_rvalue1 - 76 ~
#include <iostream>
using namespace std;

// 임시객체 개념
class Point
{
	int x, y;
public:
	Point()  { cout << "생성자" << endl; }
	~Point() { cout << "소멸자" << endl; }
	Point(const Point&) { cout << "복사생성자" << endl; }
};

//Point p1; // 전역객체

int main()
{
	cout << "AAA" << endl;
	
	//Point p1; // 지역 객체 - 자신은 선언한 블럭을 벗어 날때 파괴

	Point(); // 임시객체 - 자신이 포함된 문장이(full expression) 끝날때 파괴된다.
			 // 클래스이름() 로 만든다.
			 // unnamed object(이름없는객체)라고도 표현!
			 // C++ 표준문서 12.2 항목에서 자세히 설명

	cout << "BBB" << endl;
}




