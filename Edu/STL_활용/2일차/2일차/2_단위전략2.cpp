#define _CRT_SECURE_NO_WARNINGS
#include "show.h"

// STL string �� ����
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

// ��åŬ���� : Ư�� Ŭ������ ����ϴ� �پ��� ��å�� ���� Ŭ����
//				����å, �޸� �Ҵ� ��å ��...
//				��� ��å Ŭ������ ���Ѿ� �ϴ� ��Ģ�� �ִ�.

// string�� �� ��å Ŭ���� : compare, eq, lt ���� static �Լ��� �־�� �Ѵ�.

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
		cout << "���� ���ڿ�" << endl;
	else
		cout << "�ٸ� ���ڿ�" << endl;
}