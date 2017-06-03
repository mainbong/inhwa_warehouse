
// 상수의 위치에 대한 이야기!! 
int main()
{
	// 아래 2줄은 완전히 동일합니다.
	const int c1 = 10;
	int const c2 = 20; 

	// 상수 포인터와 상수를 가르키는 포인터
	int n = 10;
	const int* p1 = &n; // p1을 따라가면 상수
	int* const p2 = &n; // p2가 상수, p2를  따라가면  int가 있음.

	// 참조
	int& r1 = n;
	const int*& r2 = p1;
	int* const& r3 = p2;
}