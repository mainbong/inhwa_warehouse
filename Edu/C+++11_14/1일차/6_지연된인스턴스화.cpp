// 6_�������ν��Ͻ�ȭ - ���翡 ���� �ֽ��ϴ�.
/*
class AAA
{
public:
	void foo(int a) { *a = 10; } // a�� int�̹Ƿ� *a �Ҽ� ����.- error
};
*/
// �Լ�/Ŭ���� ���ø��� ������ ������ ���� �Լ��� �������¾ʴ´�.
// "Lazy Instantiatioin" �̶�� ����!
template<typename T> class AAA
{
public:
	void foo(T a) { *a = 10; }
};

int main()
{
	//AAA aaa; // ������ �ϸ� �� ������ �������� ������ ������

	AAA<int> aaa;
	//aaa.foo(0); // foo�� ����ؾ߸� error �߻�
}