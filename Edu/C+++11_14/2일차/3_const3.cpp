
// C++11은 컴파일 상수 전용 키워드를 도입합니다. - 60 page

// constexpr 함수 : 모든 인자는 컴파일시간 상수만 전달해야 한다.
constexpr int Add(int a, int b) { return a + b; }

int main()
{
	int n = 10;
	constexpr int c1 = 10; // ok..
//	constexpr int c2 = n;  // error

	// 배열의 크기로 함수를 넣을수도 있습니다.
	int x[Add(3, 5)];
}

// 배열 크기에 대한 혼란
// C89 : 배   열크기는 컴파일 시간 상수 이어야 한다.
// C99 : 배열 크기로 변수를 보낼수 있다. - gcc, clang 지원
//							 gcc를 제외한 대부분 컴파일러(VC, 볼랜드) 지원 안함















