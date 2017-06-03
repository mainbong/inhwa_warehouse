// ��Ģ 2. Universal Reference �ϋ�
//		-move�� perfect forwarding ������ �����Ģ.. 

// expr��
// lvalue �̸� : T => lvalue reference ��, int&
// rvalue �̸� : T => rvalue reference ��, int&&

// & & => &
// & && => &
// && & => &
// && && => &&
template<typename T> void foo(T&& param)
{
	static_cast<T&&>(param); // static_cast<int& &&>(param) =>static_cast<int&>(param)
							 // static_cast<int&& &&>(param)=>static_cast<int&&>(param)
}

int main()
{
	int n = 10;
	foo(n);
	foo(10);

}