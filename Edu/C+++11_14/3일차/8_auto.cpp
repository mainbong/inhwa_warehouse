#include <iostream>
using namespace std;

// auto�� �Լ�����!!
/*
template<typename T, typename U> 
decltype(a*b) Mul(T a, U b)  // a,b�� ����Ǳ� ���� ���ǰ� �ִ�. error
{
	return a * b;
}
*/
/*
// C++11���� ok..
template<typename T, typename U>
auto Mul(T a, U b) -> decltype(a*b)
{
	return a * b;
}
*/
// ���Ϲ����� auto �� �߷��Ҽ� �� �ִ�.
// ����. auto ���� ���� �ϸ� ������ �����ϰ� �ȴ�.
/*
template<typename T, typename U>
auto Mul(T a, U b) 
{
	return a * b;
}
*/
// c++14 ���� �Ʒ� ó�� �մϴ�.
template<typename T, typename U>
decltype(auto) Mul(T a, U b)
{
	return a * b;
}



int main()
{
	cout << Mul(3.4, 2) << endl;
}






