// 5_typename - 6 page!!
// 교재 1-2의 내용은 C++11을 이해하기 위해서 C++98에 있던..
// 어려운 내용의 정리 입니다.

class AAA
{
public:
	//......
	//static int DWORD;
	typedef int DWORD;
};
int p = 0;

template<typename T> typename T::DWORD  foo(T aaa)
{
	// T::타입 을 사용하려면 typename을 붙여야 한다.
	typename T::DWORD * p; // 이 한줄을 해석해 보세요.. DWORD는 뭘까요 ?
				// 1. DWORD는 static 변수인데 곱하기 p하고 있다
				// 2. DWORD는 T안에 있는 typedef된 타입이다.
				//    포인터 변수 p를 선언하고 있다.
	return 0;
}

int main()
{
	AAA a;
	foo(a);
}







