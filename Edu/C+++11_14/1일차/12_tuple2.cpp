#include <iostream>
using namespace std;

// tuple ����� - 45 page
// 1. �������� ���ø����� �ؾ� �Ѵ�.
// 2. ù��° ���ø� ���ڴ� �������� Ÿ������ �޾ƾ� �Ѵ�.

template<typename T, typename  ... Types> 
class xtuple : public xtuple<Types...>
{
public:
	T value;

	static const int N = xtuple<Types...>::N + 1;  // �θ�::N + 1
};

// xtuple�� ���ø� ���� �Ѱ� �϶��� ���� �κ� ����ȭ
template<typename T> class xtuple<T>  // ���ڰ� �Ѱ� �϶�!!
{
public:
	T value;

	static const int N = 1; // ����� ����
};

int main()
{
	//      �θ� xtuple<char>     // char value;
	// �θ�  xtuple<double, char> // double value ����
	xtuple<int, double, char> t3; // int value ����.
}









