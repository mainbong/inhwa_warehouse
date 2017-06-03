#include <iostream>
using namespace std;

template<typename T, typename  ... Types>
class xtuple : public xtuple<Types...>
{
	typedef xtuple<Types...> BaseType;
public:
	T value;

	xtuple() {}
	xtuple(const T& v, const Types& ... args) : value(v), BaseType(args...) {}

	static const int N = BaseType::N + 1;
};

template<typename T> class xtuple<T>
{
public:
	T value;
	xtuple() {}
	xtuple(const T& v) : value(v) {}

	static const int N = 1;
};

// Tuple T�� N��° ����� Ÿ���� ���ϴ� ��Ÿ �Լ�
template<int N, typename T> struct xtuple_element {};


// N�� 0�϶��� ���� �κ� ����ȭ..
template<typename T, typename ... Types> 
struct xtuple_element<0, xtuple<T, Types...>>
{
	typedef T type;
	typedef xtuple<T, Types...> tupleType; // 0��° ��Ҹ� ���� Ʃ�� ���
};
// N�� 0�� �ƴҶ�
template<int N, typename T, typename ... Types>
struct xtuple_element<N, xtuple<T, Types...>> 
	: public xtuple_element<N-1, xtuple< Types... >>
{
};

template<int N, typename T>
typename xtuple_element<N, T>::type&
xget(T& tp)
{
	return ((typename xtuple_element<N, T>::tupleType&)tp).value;
}



//����.
//xtuple_element<0, Ʃ��>::type; 
//xtuple_element<3, Ʃ��>::type;

/*
// tuple T���� N��° ����� ���� ������ �Լ�
template<int N, typename T> 
T�� �ִ� N��° ���Ÿ��& 
xget(T& tp)
{
	return ((N��°�θ�Ÿ��&)tp).value;
}
*/
int main()
{
	//      �θ� xtuple<char>     // char value;
	// �θ�  xtuple<double, char> // double value ����
	xtuple<int, double, char> t3(1, 4.4, 'a'); // int value ����.



	// t3 Ʃ�ÿ��� 1��° ���� ������ �Լ�
	double d = xget<1>(t3);

	cout << d << endl;
}









