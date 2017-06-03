
//void foo(int& a) {}
//void goo(int p) {}

template<typename T> void foo(T& a) {}
template<typename T> void goo(T p) {}

int main()
{
	const int c = 10;
	foo(c); // ok.. T가 const int로 결정.

	int n = 10;
	goo(&n); // ok.. T가 int* 로 결정..
}