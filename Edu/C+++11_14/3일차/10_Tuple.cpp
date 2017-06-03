// 10_tuple
#include <iostream>
#include <typeinfo>
using namespace std;

// 1�������� �����������ø� 5.cpp   xtuple 2�� �����ؿ�����.. -

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
//--------------------------------------------
// T Ʃ�ÿ��� N�� Ÿ���� ���ϴ� traits
// T : Ʃ��
// N : �˰��� �ϴ� ����� index( 0 ���)
template<int N, typename T> struct GetType
{
};

// Ÿ���� ���Ҽ� �ֵ��� �κ� ����ȭ �Ѵ�.
// 1. 0��° Ÿ�Ը� ������ ���ô�.
/*
template<typename T > struct GetType<0, T>
{
	// T���� 0��° Ÿ���� ���Ҽ� ����. - �κ�����ȭ�� �߸��ߴ�
};
*/
/*
template<typename T > struct GetType<0, xtuple<T>>
{
	// ���ڰ� �Ѱ��� tuple �� ����Ҽ� �ִ� ����̴� - �κ� ����ȭ �߸��ߴ�
};
*/

/*
template<typename ... Types > struct GetType<0, xtuple<Types...>>
{
	// ���ڰ� �������� tuple�� �����Ҽ� �ְ� �Ǿ���.
	// ������ tuple<Types...>�� 0��° Ÿ���� ���Ҽ� ����. - �߸��������
};
*/
template<typename T, typename ... Types > 
struct GetType<0, xtuple<T, Types...>>
{
	typedef T type; // 1��° ��� Ÿ��
	typedef xtuple<T, Types...> tupleType; // Ʃ�� Ÿ��
};

// N��° Ÿ�� �˾Ƴ���
template< int N , typename T, typename ... Types> 
struct GetType<N, xtuple<T, Types...>  > //: public GetType<N - 1, xtuple<Types...>>
{
	typedef typename GetType<N-1, xtuple<Types...>>::type  type;
	typedef typename GetType<N-1, xtuple<Types...>>::tupleType  tupleType;
};
/*
// �ᱹ get�� 
template<int N, typename T> 
N��° ��� Ÿ��&
xget(T& tp)
{
	return ((N��°��Ҹ� ���� Ʃ�� Ÿ��&)tp).value;
}
*/

template<int N, typename T>
typename GetType<N,T>::type&
xget(T& tp)
{
	return ((typename GetType<N,T>::tupleType&)tp).value;
}

template<typename T> void foo(T& tp) // T : tuple<int, double, char> �Դϴ�.
{
	cout << xget<1>(tp) << endl;


	// tp�� ���� ����� 0��° Ÿ���� �˾Ƴ� ���ô�
//	typename GetType<1, T>::type  n; // n�� _int_Ÿ��
//	cout << typeid(n).name() << endl; // 
}


int main()
{
	xtuple<int, double, char> t(1, 3.3, 'a');

	foo(t);
}








