//8_유틸리티
#include "show.h"

#include <bitset> // 비트를 관리하기 위한 자료구조

int main()
{
	bitset<40> bs;

	cout << sizeof(bs) << endl;

	bs.set();	// 모두 1로
	bs.reset();	// 모두 0 으로 
	bs.set(2);	//	2번째 비트만 1
	bs.flip(1);	// 1번째 비트 뒤집기

	string		s = bs.to_string();
	unsigned long n = bs.to_ulong();

	cout << s << endl;
	cout << n << endl;
}