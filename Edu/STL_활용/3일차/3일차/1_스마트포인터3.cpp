// 1_����Ʈ������
#include "show.h"
#include <memory>  // C++�� ����Ʈ�����͸� ����ϱ� ����...

class Car
{
	int color;
public:
	Car(int c) {}
	void Go() { cout << "Car Go" << endl; }
	~Car() { cout << "Car Destroy" << endl; }
};


// new ������
void* operator new(size_t sz)
{
	cout << "new : "<< sz << endl;
	return malloc(sz);
}

void operator delete(void* p)
{
	free(p);
}


int main()
{
	// �Ʒ� �ڵ尡 ����Ǹ� �޸� �Ҵ��� ��� �Ͼ��� ?
	shared_ptr<Car> p1(new Car(10)); // Car ��ü�� �޸����������� ����� ���� 2���� �޸� �Ҵ��� �Ͼ��.
	// �޸����� ���������� ���� ���� �޸� ������ ����ϴµ� �̰��� ���� ��������� �޸� ����ȭ ������ �Ͼ �������Ϸ� ����Ǳ� �ʹ�.
	// �׷��ٸ� �޸����� ������������ ��ü�� �������� ��� ?

	// sizeof(Car) + sizeof(��������������ü) ũ�⸦ �ѹ��� �޸� �Ҵ�
	shared_ptr<Car> p2 = make_shared<Car>(10);
}