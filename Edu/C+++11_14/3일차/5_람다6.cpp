#include <iostream>
#include <algorithm>
using namespace std;

// ����ǥ����(Lambda Express) : �Լ� ��ü�� ����� ǥ����

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// [] : Lamda Introducer, ���ٰ� ���۵��� �˸��� ǥ��
	sort(x, x + 10, [](int a, int b) { return a < b; });

	// �� ������ ������ �ϸ� - 65page
	// Ŭ����(Closure) : ���� ǥ������ ���ؼ� �����Ϸ��� ���� Ŭ����
	class Closure_Object
	{
	public:
		inline int operator()(int a, int b) const 
		{
			return a < b; 
		}
	};
	
	sort(x, x + 10, Closure_Object() );
}








