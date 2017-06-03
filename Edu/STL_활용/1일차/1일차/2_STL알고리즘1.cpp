// 2_STL알고리즘1.cpp - 교재 2 page
#include <iostream>
using namespace std;

// 1단계. strchr() 함수 만들기
char* xstrchr(char* s, char value)
{
	while (*s != 0 && *s != value)
		++s;
	return *s == 0 ? 0 : s;
}

int main()
{
	char s[] = "abcdefghijk";

	char* p = xstrchr(s, 'c');

	if (p == 0)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}