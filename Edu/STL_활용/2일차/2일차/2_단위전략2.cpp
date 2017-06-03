#define _CRT_SECURE_NO_WARNINGS
#include "show.h"

// STL string 의 원리
/*
template<typename T, 
	typename Traits = char_traits<T>,
	typename Alloc = allocator<T>>
class basic_string
{
	T* buff;
public:
	bool operator==(const basic_string& s)
	{
		if (Traits::equal(buff, s.buff))
			return true;
		return false;
	}
};
typedef basic_string<char> string;
typedef basic_string<wchar_t> wstring;
*/

// 정책클래스 : 특정 클래스가 사용하는 다양한 정책을 담은 클래스
//				비교정책, 메모리 할당 정책 등...
//				모든 정책 클래스는 지켜야 하는 규칙이 있다.

// string의 비교 정책 클래스 : compare, eq, lt 등의 static 함수가 있어야 한다.

class MyCharTraits : public char_traits<char>
{
public:
	static bool eq(char a, char b) { return toupper(a) == toupper(b); }
	static bool lt(char a, char b) { return toupper(a) < toupper(b); }

	static bool compare(const char* a, const char* b, int sz)
	{
		return _memicmp(a, b, sz);
	}
};

typedef basic_string<char, MyCharTraits> cstring;

int main()
{
	cstring s1 = "abcd";
	cstring s2 = "ABCD";

	if (s1 == s2)
		cout << "같은 문자열" << endl;
	else
		cout << "다른 문자열" << endl;
}