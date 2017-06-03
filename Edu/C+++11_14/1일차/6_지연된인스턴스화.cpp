// 6_지연된인스턴스화 - 교재에 빠져 있습니다.
/*
class AAA
{
public:
	void foo(int a) { *a = 10; } // a는 int이므로 *a 할수 없다.- error
};
*/
// 함수/클래스 템플릿은 사용되지 않으면 실제 함수를 만들지는않는다.
// "Lazy Instantiatioin" 이라는 개념!
template<typename T> class AAA
{
public:
	void foo(T a) { *a = 10; }
};

int main()
{
	//AAA aaa; // 컴파일 하면 왜 에러가 나오는지 생각해 보세요

	AAA<int> aaa;
	//aaa.foo(0); // foo를 사용해야만 error 발생
}