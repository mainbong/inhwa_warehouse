// 2_STL알고리즘1.cpp - 교재 2 page
#include <iostream>
using namespace std;

// 일반화 (Generic) 프로그래밍 : 하나의 함수(클래스)를 최대한 활용 범위를
//								넓혀서 만들자는 개념..



// 2단계. 검색 구간의 일반화 - 부분 문자열 검색이 가능하게 하자.

char* xstrchr(char* first, char* last, char value)
{
	while (first != last && *first != value)
		++first;
	return first == last ? 0 : first;
}

int main()
{
	char s[] = "abcdefghijk";

	char* p = xstrchr(s, s+5, 'c');

	if (p == 0)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}