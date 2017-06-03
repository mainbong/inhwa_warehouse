/*
void foo(int&&) // ���ڴ� rvalue�� ������ �ִ�.
{
	cout << "foo" << endl; 
}
*/

// int&  : lvalue reference => lvalue�� �޴´�.
// int&& : rvalue reference => rvalue�� �޴´�.

// T&&   : universal reference(forward reference) - 108 page
//		   lvalue�� ���޵Ǹ� lvalue reference�� �ǰ�
//				T : int& �ǹǷ� T&&�� int& && => int&

//         rvalue�� ���޵Ǹ� rvalue reference�� �ȴ�.
//				T : int&& �ǹǷ� T&& �� int&& && => int&&


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
	foo(r); // T : int& �߷еǾ��ٸ� a�� int& &&
}






