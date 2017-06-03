// 1_typedef2
#include "show.h"

// �־��� ������ ���� ���ϴ� �Լ�
/*
int sum(int* first, int* last)
{
	int s = 0;
	while (first != last) {
		s = s + *first;
		++first;
	}
	return s;
}
*/

// �ݺ����� ����
// 1. ��¥ ������
// 2. ��ü�� �ݺ���..
// �� 2���� ������ ������ �Ϲ�ȭ �Լ��� ����� ��ƽ��ϴ�.
// �ذ�å
/*
template<typename T> struct iterator_traits
{
	typedef typename T::value_type value_type;
};

// �����ʹ� �̸��� ������ !! �Ϳ�! ������ ���ø�
template<typename T> struct iterator_traits<T*>
{
	typedef T value_type;
};
*/
// �ݺ��ڵ� �ڽ��� ����Ű�� Ÿ���� �ֽ��ϴ�. T::value_type

template<typename T> typename iterator_traits<T>::value_type sum(T first, T last)
{
	// �ٵ� �䷸�� ����ϱ� x[10]�� ���� sum �� �ȵǳ�.
	//typename T::value_type s = 0;
	// �����ͱ��� �޾ƿü� �ִ� ����Ÿ���� ���Ͽ�!

	typename iterator_traits<T>::value_type s = 0;
	// auto �� �Ἥ �Ʒ��� ���� ��������!
//	auto s = *first;
//	first++;

	while (first != last) {
		s = s + *first;
		++first;
	}
	return s;
};

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << sum(x, x + 10) << endl;

	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	cout << sum(v.begin(), v.end()) << endl;
}