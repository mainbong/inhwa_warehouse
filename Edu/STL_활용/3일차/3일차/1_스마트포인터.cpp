// 1_����Ʈ������
#include "show.h"
#include <memory>  // C++�� ����Ʈ�����͸� ����ϱ� ����...

class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
	~Car() { cout << "Car Destroy" << endl; }
};

int main()
{
	shared_ptr<Car> p = new Car; // ERROR
	shared_ptr<Car> p(new Car); // OK. �����ڰ� explicit �������̱� ����.

	p->Go(); // p.operator->() �� �����Դϴ�.
			// -> ������ ������ ���.
	//Car* p = new Car;
	//delete p;
}