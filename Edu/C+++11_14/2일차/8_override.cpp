// 8_override- 73 page.. ������ ����

class Base
{
public:
	virtual void foo(int a) {}
	virtual void goo() const {}
	void hoo() {}
};
/*
class Derived : public Base
{
public:
	// ������ �������� �Ǽ��� ��� ������
	virtual void foo() {}		// 1. �Ǽ� ���ڰ� ����
	void foo(int a) {}			// 2. ok..
	virtual void foo(double d) {} // 3. �Ǽ�. ���� Ÿ���� �ٸ���
	virtual void goo() {}		  // 4. �Ǽ�, ��� �Լ��̾�� �Ѵ�.
	virtual void gooo() const {}	 // 5. �Ǽ� �Լ��̸��� Ʋ�ȴ�
	void hoo() {}					// 6. ���������� ������ �����Լ��� �ƴ��Լ���
									//    ������ �ϴ� ���� ���� �ʴ�.
};
*/

class Derived : public Base
{
public:
	// ������ �������� �Ǽ��� ��� ������
	//virtual void foo() override {}		// 1. �Ǽ� ���ڰ� ����

	// final �����Լ� : ���̻� �ڽ��� ������ �Ҽ� ���� �Ѵ�.
	void foo(int a) override final {}			// 2. ok..
	//virtual void foo(double d)override {} // 3. �Ǽ�. ���� Ÿ���� �ٸ���
//	virtual void goo() override {}		  // 4. �Ǽ�, ��� �Լ��̾�� �Ѵ�.
//	virtual void gooo()  const override{}	 // 5. �Ǽ� �Լ��̸��� Ʋ�ȴ�
//	void hoo() override {}					// 6. ���������� ������ �����Լ��� �ƴ��Լ���
									//    ������ �ϴ� ���� ���� �ʴ�.
};
int main()
{
}





