#include <iostream>
using namespace std;

// ranged-for의 원리 - 26 page
struct Point3D
{
	int x, y, z;
};
// 사용자 정의 복합객체를 ranged_for에 적용하려면 begin(), end()가 필요합니다.
const int* begin(const Point3D& p) { return &(p.x); }
const int* end(const Point3D& p)   { return &(p.z) + 1; } // past the end : 마지막다음요소


int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (auto n : x) // 이 한줄의 원리는 뭘까요 ?
		cout << n << endl;

	// 위 한줄은 컴파일 하면 아래 코드가 됩니다.
	/*
	for (auto p = begin(x); p != end(x); ++p)
	{
		auto n = *p;
		
		// 이제 사용자 코드
		cout << n << endl;
	}
	*/

	Point3D p3d;

	for (auto n2 : p3d) // 될까요 ?
	{
		cout << n2 << endl;
	}
}





