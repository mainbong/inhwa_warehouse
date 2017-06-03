// 13_template_alias2
#include <type_traits>
using namespace std;

// C++14에 아래 코드가 있습니다.
//template<typename T>
//using remove_reference_t = typename remove_reference<T>::type;

template<typename T> void foo(T a)
{
	// T에서 레퍼런스를 제거한 타입의 변수 n을 선언해 보세요.
	typename remove_reference<T>::type  n;

	remove_reference_t<T> n1; // 위와 동일!
}


int main()
{
	int n = 10;
	int& r = n;
	foo<int&>(r);
}


template<class _Ty> inline
_CONST_FUN remove_reference_t<_Ty>&&
move(_Ty&& _Arg) _NOEXCEPT
{	// forward _Arg as movable
	return (static_cast<typename remove_reference<_Ty>::type&&>(_Arg));
}

