// 1_typedef
#include "show.h"

/*
void print_first_element(vector<int>& v)
{
	int n = v.front();
	cout << n << endl;
}
*/
/*
template<typename T>
void print_first_element(vector<T>& v)
{
	T n = v.front();
	cout << n << endl;
}
*/


template<typename T>
void print_first_element(T& v)
{
	// T : list<double>
	// T::value_type : list<double>::value_type => double
	typename T::value_type n = v.front(); // Ŭ�����̸�::blahblah�� ���� �ִ� ǥ������ 
	// static ����� typedef �ΰ����� ���� �� �ֱ� ������
	// �ڽ��� ������ Ÿ���� ��쿡��(T�ϰ��) type ���� ���޶�� �ǹ��� typename ���ξ �ʿ��ϴ�.
	cout << n << endl;
}

int main()
{
	list<double> v = { 1,2,3 };

	//int sz = v.size(); // ?

	list<double>::size_type sz = v.size();

	print_first_element(v);
}

// Template ��� �����̳ʴ� �ڽ��� �����ϴ� Ÿ���� �ֽ��ϴ�.
// �ܺο��� �˰� ���� ���� �ֽ��ϴ�. (print_first_element)
// �׷��� �Ʒ�ó�� ��������ϴ�.

/*
template<typename T> class list
{
public:
	typedef T value_type;
	//..............
};

list<int> s = { 1,2,3 };
list<int>::value_type n = s.front(); // ���⼭ n�� _int_ Ÿ���Դϴ�.
*/