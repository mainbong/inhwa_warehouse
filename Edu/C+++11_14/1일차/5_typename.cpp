// 5_typename - 6 page!!
// ���� 1-2�� ������ C++11�� �����ϱ� ���ؼ� C++98�� �ִ�..
// ����� ������ ���� �Դϴ�.

class AAA
{
public:
	//......
	//static int DWORD;
	typedef int DWORD;
};
int p = 0;

template<typename T> typename T::DWORD  foo(T aaa)
{
	// T::Ÿ�� �� ����Ϸ��� typename�� �ٿ��� �Ѵ�.
	typename T::DWORD * p; // �� ������ �ؼ��� ������.. DWORD�� ����� ?
				// 1. DWORD�� static �����ε� ���ϱ� p�ϰ� �ִ�
				// 2. DWORD�� T�ȿ� �ִ� typedef�� Ÿ���̴�.
				//    ������ ���� p�� �����ϰ� �ִ�.
	return 0;
}

int main()
{
	AAA a;
	foo(a);
}







