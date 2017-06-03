// 13_template_alias2
#include <type_traits>
using namespace std;

// C++14�� �Ʒ� �ڵ尡 �ֽ��ϴ�.
//template<typename T>
//using remove_reference_t = typename remove_reference<T>::type;

template<typename T> void foo(T a)
{
	// T���� ���۷����� ������ Ÿ���� ���� n�� ������ ������.
	typename remove_reference<T>::type  n;

	remove_reference_t<T> n1; // ���� ����!
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

