// 15_스마트포인터
#include <iostream>
using namespace std;

#include <memory>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
//    Point* innerPoint;
    virtual ~Point() { cout << __FUNCTION__ << "is Called." << endl;}
};

int main()
{
//	shared_ptr<Point> p1(new Point);
//	shared_ptr<Point> p2 = p1; // 참조계수 방식..

  //  Point* p1 = new Point(1,2);
  //  p1->innerPoint = new Point(2,3);
	shared_ptr<Point> p1 = make_shared<Point>(1, 2);
					// sizeof(Point) + sizeof(참조계수변수) 로 메모리 할당
					// 객체와 참조계수를 동일 메모리에 놓는다.
}
