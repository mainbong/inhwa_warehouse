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
	typename T::value_type n = v.front(); // 클래스이름::blahblah로 쓸수 있는 표현에는 
	// static 멤버와 typedef 두가지가 있을 수 있기 때문에
	// 자신이 임의의 타입일 경우에는(T일경우) type 으로 봐달라는 의미의 typename 접두어가 필요하다.
	cout << n << endl;
}

int main()
{
	list<double> v = { 1,2,3 };

	//int sz = v.size(); // ?

	list<double>::size_type sz = v.size();

	print_first_element(v);
}

// Template 기반 컨테이너는 자신이 저장하는 타입이 있습니다.
// 외부에서 알고 싶을 때가 있습니다. (print_first_element)
// 그래서 아래처럼 만들었습니다.

/*
template<typename T> class list
{
public:
	typedef T value_type;
	//..............
};

list<int> s = { 1,2,3 };
list<int>::value_type n = s.front(); // 여기서 n은 _int_ 타입입니다.
*/