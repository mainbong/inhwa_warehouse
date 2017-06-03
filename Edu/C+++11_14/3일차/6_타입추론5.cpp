// 규칙 2. Universal Reference 일떄
//		-move와 perfect forwarding 때문에 생긴규칙.. 

// expr이
// lvalue 이면 : T => lvalue reference 즉, int&
// rvalue 이면 : T => rvalue reference 즉, int&&

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