#include <iostream>
#include <algorithm> // 비교 정책을 변경할수 있는 sort()가 있습니다.
#include <functional> // less<>, greater<> 함수 객체가 있습니다.
#include "logtime.h"  // 파일 복사해오세요
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
		// 비교 정책으로 STL의 함수객체를 사용하는 코드
		sort(x, x + 1000, less<int>() );
		sort(x, x + 1000, greater<int>() );
	}
}
// qsort()비교 함수
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
// Release Mode로 빌드해 보세요..
