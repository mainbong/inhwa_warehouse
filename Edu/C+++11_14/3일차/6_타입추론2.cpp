
// T와  ParamType 개념
template<typename T> void foo(const T& param)
{
}

int main()
{
	int n = 0;
	foo(n);   // T : int   param : const int&
}
// Effective Modern C++의 내용입니다
// 규칙 1. ParamType 이 포인터이거나 참조 일때
// 규칙 2. ParamType 이 Universal Reference 일때
// 규칙 3. ParamType 이 포인터나 참조가 아닐때

// 함수인자 : expr  
// foo(r+1): expr => r+1




