
//void foo(int& a) {}
//void goo(int p) {}

template<typename T> void foo(T& a) {}
template<typename T> void goo(T p) {}

int main()
{
	const int c = 10;
	foo(c); // ok.. T�� const int�� ����.

	int n = 10;
	goo(&n); // ok.. T�� int* �� ����..
}