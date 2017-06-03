// 2_사용자정의상수 -114 page - 3번
#include <iostream>
using namespace std;

class Meter
{
	int value;
public:
	Meter(int n = 0) : value(n) {}
	void print() { cout << value << endl; }
};

Meter operator""m(unsigned long long a)
{
	return Meter(a);
}

int main()
{
	float f = 3.4f; // f, s,l
	Meter n = 3m; // operator""m(3)
	n.print();


}
