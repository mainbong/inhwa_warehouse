#include "show.h"
#include <tuple>

// STL 선형컨테이너.
// C++98 : vector, list, deque
// C++11 : forward_list, array, tuple


int main()
{
	vector<int> v(10); // 10 개가 모두 int Homogeneous

	// 서로 다른 타입 보관.
	tuple<int, char, long, double, short> t(1, 'a', 3, 4.3, 7);
	
	get<0>(t) = 10;
	int n = get<0>(t);

	cout << n << endl; // 10
}