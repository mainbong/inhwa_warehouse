// �� �Լ� ��ü�� ����ϴ°� ? 

// �ٽ�
// 1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� ����.
//    signature(���ڿ� ����Ÿ���� ���)�� ������ �Լ��� ��� ���� Ÿ���̴�.

// 2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�.
//    signature�� �����ص� ��� �Լ���ü�� �ٸ� Ÿ���̴�.

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less    { inline bool operator()(int a, int b) { return a < b; }};
struct Greater { inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	bool(*f1)(int, int);
	f1 = &cmp1;
	f1 = &cmp2;

	Less    f2;
	Greater f3;
}

