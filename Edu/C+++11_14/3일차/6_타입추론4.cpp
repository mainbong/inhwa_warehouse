// 규칙 1. ParamType이 포인터나 참조일때 - 92 page 
// => expr의 레퍼런스만  무시한다.
template<typename T> void foo(T& param){}
template<typename T> void goo(const T& param) {}

int main()
{
	int n = 10;
	const int c = n;
	const int& r = c;
	foo(n); // T : int			param : int&
	foo(c);	// T : const int	param : const int&
	foo(r); // T : const int	param : const int&

	goo(n); // T : int		param : const int&
	goo(c);	// T : int 		param : const int&
	goo(r); // T : int 		param : const int&

}

