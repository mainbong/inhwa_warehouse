
int main()
{
	int x1[10];

	// ������ ������ ��� ������..!!
	int s1 = 10;
	//int x2[s1]; // 1. error �迭ũ��� ������ �ɼ� ����.

	const int s2 = 10;
	int x3[s2]; // 2. ok.

	const int s3 = s1;
//	int x4[s3]; // 3. error. �迭ũ��� compile time ����� �����ϴ�.

	foo(s1)
}

void foo(const int c)
{
	int x[c]; // error. c�� runtime ���
}