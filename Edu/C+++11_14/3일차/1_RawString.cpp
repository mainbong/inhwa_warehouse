// 1_RawString - 115 page
#include <iostream>
using namespace std;

int main()
{
	// 기존 문자열 "\"를 표현하려면 "\\" 해야 한다.
	//  - 디렉토리경로나 정규 표현식사용시 복잡해진다.
	const char* s1 = "C:\\AA\\b.txt";

	// C++11의 RawString 문법 - R"( 문자열 )"
	const char* s2 = R"(C:\AA\b.txt)";

	cout << s2 << endl;

	// 1. "를 사용하고 싶으면 그냥 사용하면 된다
	const char* s3 = R"(AAA"BBB)";
	cout << s3 << endl;

	const char* s4 = R"(AAA"(BBB)";
	cout << s4 << endl;

	// 문제점 : 문자열 중간에 )" 를 사용하고 싶을때
	//const char* s5 = R"(AAA)"BBB)";
	//cout << s5 << endl;

	// 해결책.. 사용자 정의 토큰을 추가한다.
	const char* s6 = R"***(AAA)"BBB)***";
	cout << s6 << endl;

}









