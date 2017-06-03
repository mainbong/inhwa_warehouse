
int main()
{
	int x1[10];

	// 다음중 에러를 모두 고르세요..!!
	int s1 = 10;
	//int x2[s1]; // 1. error 배열크기는 변수가 될수 없다.

	const int s2 = 10;
	int x3[s2]; // 2. ok.

	const int s3 = s1;
//	int x4[s3]; // 3. error. 배열크기는 compile time 상수만 가능하다.

	foo(s1)
}

void foo(const int c)
{
	int x[c]; // error. c는 runtime 상수
}