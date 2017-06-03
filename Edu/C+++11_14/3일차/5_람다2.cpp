// 왜 함수 객체를 사용하는가 ? 

// 핵심
// 1. 일반 함수는 자신만의 타입이 없다.
//    signature(인자와 리턴타입의 모양)이 동일한 함수는 모두 같은 타입이다.

// 2. 함수 객체는 자신만의 타입이 있다.
//    signature가 동일해도 모든 함수객체는 다른 타입이다.

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less    { inline bool operator()(int a, int b) { return a < b; }};
struct Greater { inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	bool(*f1)(int, int);
	f1 = &cmp1;
	f1 = &cmp2;

	Less    f2;
	Greater f3;
}

