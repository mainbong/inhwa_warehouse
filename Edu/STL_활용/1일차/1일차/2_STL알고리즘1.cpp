// 2_STL�˰���1.cpp - ���� 2 page
#include <iostream>
using namespace std;

// 1�ܰ�. strchr() �Լ� �����
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
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}