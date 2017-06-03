//8_��ƿ��Ƽ
#include "show.h"

#include <bitset> // ��Ʈ�� �����ϱ� ���� �ڷᱸ��

int main()
{
	bitset<40> bs;

	cout << sizeof(bs) << endl;

	bs.set();	// ��� 1��
	bs.reset();	// ��� 0 ���� 
	bs.set(2);	//	2��° ��Ʈ�� 1
	bs.flip(1);	// 1��° ��Ʈ ������

	string		s = bs.to_string();
	unsigned long n = bs.to_ulong();

	cout << s << endl;
	cout << n << endl;
}