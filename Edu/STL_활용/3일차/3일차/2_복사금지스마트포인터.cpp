// 2_�����������Ʈ������
#include "show.h"
#include <memory>

int main()
{
	shared_ptr<int> p1(new int); // �ڿ� + ������ü ����.
	shared_ptr<int> p2 = p1;

	unique_ptr<int> up1(new int); // ������ü�� ����.
								// �Ҹ��ڿ��� delete ��ɸ� ����.
	//unique_ptr<int> up2 = up1; // error

	unique_ptr<int> up2 = move(up1); // ����� �ȵ����� move �� �ȴ�. move �� �����͸� �ѱ�� �ڽ��� ���������ϱ�

	*up2 = 10;

	cout << *up2 << endl; // ok...

	//*up1 = 10; // runtime error - up1�� �ڿ��� up2�� ���޵Ǿ���.!!

	cout << sizeof(up2) << endl; // ����� ���� �����Ϳ� ����! �����ڵ�δ� ���������Ϳ� �ٸ��ٰ� ����. ���� �������ϰ� ����.
}