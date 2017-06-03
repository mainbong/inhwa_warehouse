// 4_initializer_list2
#include <iostream>
#include <vector>
using namespace std;

// 생성자와 initializer_list - 33 page

class Point
{
	int x, y;
public:
	Point()				{ cout << "Point()" << endl; }
	Point(int a, int b) { cout << "Point(int,int)" << endl; }
	Point(initializer_list<int> e) { cout << "Point(initializer_list)" << endl; }
};
int main()
{
	// 어느 함수를 호출할지 예측해 보세요
	Point p1;			// 1
	Point p2(1, 1);		// 2번 없으면 error
	
	Point p3{1, 1 };    // 3번 없으면 2번 호출
//	Point p4(1, 2, 3);  // error ?
	Point p5{ 1,2,3 };  // 3번 없으면 error

	// 핵심 객체 초기화에  {} 사용해서 가변 갯수를 받을수 있다.

	// 1 ~ 10 으로 초기화된 vector만들기
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };//ok.. 편해 졌다
}

