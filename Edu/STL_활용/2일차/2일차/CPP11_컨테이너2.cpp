// CPP11_�����̳�
#include "show.h"

/*
// �迭�� ������ ������ ������ �����ϴ� �����̳�
template<typename T, int N> struct array
{
	T buff[N];
	inline int size() const { return N; }

	typedef T value_type;
	typedef T* iterator;

	inline iterator begin() { return buff ; }
	inline iterator end() { return buff + N ; }
}
*/

#include <array>
int main()
{
	int x[10];

	vector<int> v(10);

	array<int, 10> ar = { 1,2,3,4,5,6,7,8,9,10 };
	cout << ar.size() << endl;

}