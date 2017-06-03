#include <iostream>
#include <algorithm> // �� ��å�� �����Ҽ� �ִ� sort()�� �ֽ��ϴ�.
#include <functional> // less<>, greater<> �Լ� ��ü�� �ֽ��ϴ�.
#include "logtime.h"  // ���� �����ؿ�����
using namespace std;

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

void test1(int cnt)
{
	int x[1000] = { 1,3,5,7,9,2,4,6,8,10 };

	for (int i = 0; i < cnt; i++)
	{
		sort(x, x + 1000, cmp1);
		sort(x, x + 1000, cmp2);
	}
}
void test2(int cnt)
{
	int x[1000] = { 1,3,5,7,9,2,4,6,8,10 };

	for (int i = 0; i < cnt; i++)
	{
		// �� ��å���� STL�� �Լ���ü�� ����ϴ� �ڵ�
		sort(x, x + 1000, less<int>() );
		sort(x, x + 1000, greater<int>() );
	}
}
// qsort()�� �Լ�
int qsort_cmp1(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int qsort_cmp2(const void* a, const void* b) { return *(int*)b - *(int*)a; }

void test3(int cnt)
{
	int x[1000] = { 1,3,5,7,9,2,4,6,8,10 };
	for (int i = 0; i < cnt; i++)
	{
		qsort(x, 1000, sizeof(int), qsort_cmp1);
		qsort(x, 1000, sizeof(int), qsort_cmp2);
	}
}

int main()
{
	logTime(test2, 10000);
	logTime(test1, 10000);
	logTime(test3, 10000);
}
// Release Mode�� ������ ������..
