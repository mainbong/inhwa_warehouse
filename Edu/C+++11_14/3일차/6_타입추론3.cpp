// ��Ģ 3. ParamType�� �����ͳ� ������ �ƴҶ�
// => expr�� const, volatile, ���۷����� ��� �����Ѵ�.
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

