/*
void foo(int&&) // 인자는 rvalue만 보낼수 있다.
{
	cout << "foo" << endl; 
}
*/

// int&  : lvalue reference => lvalue만 받는다.
// int&& : rvalue reference => rvalue만 받는다.

// T&&   : universal reference(forward reference) - 108 page
//		   lvalue가 전달되면 lvalue reference가 되고
//				T : int& 되므로 T&&는 int& && => int&

//         rvalue가 전달되며 rvalue reference가 된다.
//				T : int&& 되므로 T&& 는 int&& && => int&&


template<typename T> void foo(T&& a)
{
	cout << "foo" << endl;
}

int main()
{
	int n = 10;
	foo(10);
	foo(n);

	int& r = n;
	foo(r); // T : int& 추론되었다면 a는 int& &&
}






