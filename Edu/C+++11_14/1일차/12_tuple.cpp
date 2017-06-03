// 12_tuple - 가변인자 템플릿의 좋은 예제 - 45page
#include <iostream>
using namespace std;

#include <tuple>

int main()
{
//	int x[10];
//	vector<int> v(10);

	// 서로 다른 타입 여러개를 보관하는 컨테이너.!
	tuple<int, double, char> t3(3, 3.2, 'a');

	// 튜플에서 요소 꺼내기
	cout << get<1>(t3) << endl; // 3.2
}



