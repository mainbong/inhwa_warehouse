// 규칙 3. ParamType이 포인터나 참조가 아닐때
// => expr의 const, volatile, 레퍼런스는 모두 무시한다.
template<typename T> void foo(T param)
{
}
int main()
{
	int n = 10;
	const int c = n;
	const int& r = c;
	foo(n); // T : int		param : int
	foo(c);	// T : int 		param : int
	foo(r); // T : int 		param : int
	foo(27); // T : int 		param : int
}

