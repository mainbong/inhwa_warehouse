// 핵심 
// 1. 아무리 인라인 함수라도 함수 포인터에 담아서 호출하는 순간 인라인 치환될수없다.
//    함수 인자로 함수를 보낼때(callback함수)인라인 치환될수 없다.
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };
/*
// 비교정책을 교체 할수 있는 Sort 함수를 생각해 봅시다.
void Sort(int* x, int n, bool(*cmp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < i; j++)

			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
	}
}

int main()
{
int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
Sort(x, 10, cmp1);
Sort(x, 10, cmp2);
}
*/
// 정책 변경이 가능하고 정책 함수를 인라인 치환 할수 있는 Sort()
// 템플릿과 함수 객체를 사용한 기술
template<typename T> void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < i; j++)
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
	}
}
int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; Sort(x, 10, f1);
	Greater f2; Sort(x, 10, f2);
}



