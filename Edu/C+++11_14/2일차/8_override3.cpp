
// ����� ��ġ�� ���� �̾߱�!! 
int main()
{
	// �Ʒ� 2���� ������ �����մϴ�.
	const int c1 = 10;
	int const c2 = 20; 

	// ��� �����Ϳ� ����� ����Ű�� ������
	int n = 10;
	const int* p1 = &n; // p1�� ���󰡸� ���
	int* const p2 = &n; // p2�� ���, p2��  ���󰡸�  int�� ����.

	// ����
	int& r1 = n;
	const int*& r2 = p1;
	int* const& r3 = p2;
}