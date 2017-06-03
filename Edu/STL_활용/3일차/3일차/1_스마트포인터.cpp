// 1_스마트포인터
#include "show.h"
#include <memory>  // C++의 스마트포인터를 사용하기 위해...

class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
	~Car() { cout << "Car Destroy" << endl; }
};

int main()
{
	shared_ptr<Car> p = new Car; // ERROR
	shared_ptr<Car> p(new Car); // OK. 생성자가 explicit 생성자이기 때문.

	p->Go(); // p.operator->() 의 원리입니다.
			// -> 연산자 재정의 기술.
	//Car* p = new Car;
	//delete p;
}