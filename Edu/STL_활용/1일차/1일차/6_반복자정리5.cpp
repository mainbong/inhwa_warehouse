#include "show.h"
// 16 page

/*
// STL 에는 5가지 반복자의 종류를 타입화 합니다.
// empty class : 아무 멤버도 없는 구조체(클래스)
//				 함수 오버로딩이나 템플릿 인자로 활용
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag			: input_iterator_tag{};
struct bidirectional_iterator_tag	: forward_iterator_tag{};
struct random_access_iterator_tag	: bidirectional_iterator_tag{};

// 이제 모든 반복자 설계자는 자신이 어떤 반복자인지 외부에 알려야 합니다.
template<typename T> class slist_iterator
{
public:
	typedef forward_iterator_tag iterator_category;
	// ++, * 등을 제공.
};
template<typename T> class vector_iterator
{
public:
	typedef random_access_iterator_tag iterator_category;
	// ++, * 등을 제공.
};
*/
template<typename T> void xadvance_imp(T& p, int n, input_iterator_tag)
{
	while (n--)++p;
}

template<typename T> void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	p = p + n;
}

// 모든 반복자를 n 만큼 전진하는 일반화 함수
template<typename T> void xadvance(T& p, int n) // n > 0 일때만 고려합니다.
{
	xadvance_imp(p, n, typename T::iterator_category()); // 타입명이므로 객체를 넘기기 위해 () 로 객체화 시킨다.
//	p = p + n;
//	while(n--) ++p; // 그러나 만약 임의접근반복자라면 이놈은 너무 성능저하가 크다!
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	vector<int>::iterator p = v.begin();

	xadvance(p, 5); // p를 5칸 전진하는 함수
	
	cout << *p << endl;
}