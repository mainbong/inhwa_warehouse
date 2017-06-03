#include "show.h"
#include <tuple>

// STL ���������̳�.
// C++98 : vector, list, deque
// C++11 : forward_list, array, tuple


int main()
{
	vector<int> v(10); // 10 ���� ��� int Homogeneous

	// ���� �ٸ� Ÿ�� ����.
	tuple<int, char, long, double, short> t(1, 'a', 3, 4.3, 7);
	
	get<0>(t) = 10;
	int n = get<0>(t);

	cout << n << endl; // 10
}