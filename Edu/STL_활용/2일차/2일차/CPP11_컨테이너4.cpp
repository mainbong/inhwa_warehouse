#include "show.h"
#include <tuple>

template<typename T> typename tuple_element<3, T>::type foo(T& a)
{
	// tuple���� 4��° ��(index 3)�� ������ �ʹ�.
	typename tuple_element<3, T>::type n = get<3>(a);
	cout << typeid(n).name() << endl; // double

	return n;
}

int main()
{

	tuple<int, char, long, double, short> t(1, 'a', 3, 4.3, 7);

	foo(t);
}