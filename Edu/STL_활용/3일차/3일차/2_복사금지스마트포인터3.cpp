#include "show.h"
#include <memory>

int main()
{
	shared_ptr<int> sp1(new int);
	unique_ptr<int> up1(new int);

	// ������ ������ ��� ��� ������.
	shared_ptr<int> sp2 = up1;			// error , ������ ������� �������� �ְڴ� ? ��!
	unique_ptr<int> up2 = sp1;			// error

	shared_ptr<int> sp3 = move(up1);	// �������� �����ϰڴ�. �׷� �����ɰ� ����!
	unique_ptr<int> up3 = move(sp1);	// �������� �� �ѱ����� �ʰ� ���� �شٰ� ������ �� ����!
}