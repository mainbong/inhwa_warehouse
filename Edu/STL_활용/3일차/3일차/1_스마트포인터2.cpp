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
	shared_ptr<Car> p1(new Car);
	cout << p1.use_count() << endl; //1
	{
		shared_ptr<Car> p2 = p1;
		cout << p1.use_count() << endl; //2
	}
	cout << p1.use_count() << endl; //1
	cout << "A" << endl;

}