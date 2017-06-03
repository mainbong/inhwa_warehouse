// �ٽ� 
// 1. �ƹ��� �ζ��� �Լ��� �Լ� �����Ϳ� ��Ƽ� ȣ���ϴ� ���� �ζ��� ġȯ�ɼ�����.
//    �Լ� ���ڷ� �Լ��� ������(callback�Լ�)�ζ��� ġȯ�ɼ� ����.
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };
/*
// ����å�� ��ü �Ҽ� �ִ� Sort �Լ��� ������ ���ô�.
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
// ��å ������ �����ϰ� ��å �Լ��� �ζ��� ġȯ �Ҽ� �ִ� Sort()
// ���ø��� �Լ� ��ü�� ����� ���
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



