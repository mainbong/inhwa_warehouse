// 2_nullptr4
#include <iostream>
using namespace std;

// nullptr�� ��ü
int main()
{
	// nullptr_t Ÿ���� ��ü!!
	nullptr_t a = nullptr;

	// nullptr_t Ÿ��
	// 1. ��� Ÿ�� �����ͷ� �Ͻ��� ��ȯ
	// 2. bool �� �Ͻ��� ��ȯ
	// 3. int�� ��ȯ �ȵ�. ������ ����� ��ȯ�� ���
	char* p1 = nullptr;
//	int   n = nullptr; // error
	bool  b = nullptr;

	int n2 = reinterpret_cast<int>(nullptr); // ok
}






