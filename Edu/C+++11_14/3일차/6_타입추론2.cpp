
// T��  ParamType ����
template<typename T> void foo(const T& param)
{
}

int main()
{
	int n = 0;
	foo(n);   // T : int   param : const int&
}
// Effective Modern C++�� �����Դϴ�
// ��Ģ 1. ParamType �� �������̰ų� ���� �϶�
// ��Ģ 2. ParamType �� Universal Reference �϶�
// ��Ģ 3. ParamType �� �����ͳ� ������ �ƴҶ�

// �Լ����� : expr  
// foo(r+1): expr => r+1




