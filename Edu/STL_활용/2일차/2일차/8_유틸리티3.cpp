// 8_��ƿ��Ƽ3
#include "show.h"
/*
template<typename T, typename U> struct pair
{
	T first;
	U second;
};
*/
pair<int,double> foo(pair<int,double> p)
{
	return p;
}

int main()
{
	//pair<int, double> p(1, 3.4);
	//foo(p);
	//foo(pair<int,double>(1, 3.4));// �ӽð�ü ���

	foo(make_pair(1, 3.4)); // �Լ� ���ø����� Ŭ�������ø� ��ü(pair)����

	pair<int, pair<int, int>> p3;
	pair<int, pair<int, pair<int, int>>> p4;
	// ������. �����ؼ� Ʃ���� ������.
}