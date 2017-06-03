// 1_스마트포인터
#include "show.h"
#include <memory>  // C++의 스마트포인터를 사용하기 위해...

class Car
{
	int color;
public:
	Car(int c) {}
	void Go() { cout << "Car Go" << endl; }
	~Car() { cout << "Car Destroy" << endl; }
};


// new 재정의
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
	// 아래 코드가 실행되면 메모리 할당이 몇번 일어날까요 ?
	shared_ptr<Car> p1(new Car(10)); // Car 객체와 메모리참조영역을 만들기 위한 2번의 메모리 할당이 일어난다.
	// 메모리참조 관리영역은 아주 작은 메모리 공간을 사용하는데 이것이 자주 만들어지면 메모리 파편화 현상이 일어나 성능저하로 연결되기 싶다.
	// 그렇다면 메모리참조 관리영역까지 객체에 합쳐지면 어떨까 ?

	// sizeof(Car) + sizeof(참조개수관리객체) 크기를 한번에 메모리 할당
	shared_ptr<Car> p2 = make_shared<Car>(10);
}