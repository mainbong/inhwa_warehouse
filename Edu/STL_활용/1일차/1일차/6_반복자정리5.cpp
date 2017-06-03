#include "show.h"
// 16 page

/*
// STL ���� 5���� �ݺ����� ������ Ÿ��ȭ �մϴ�.
// empty class : �ƹ� ����� ���� ����ü(Ŭ����)
//				 �Լ� �����ε��̳� ���ø� ���ڷ� Ȱ��
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag			: input_iterator_tag{};
struct bidirectional_iterator_tag	: forward_iterator_tag{};
struct random_access_iterator_tag	: bidirectional_iterator_tag{};

// ���� ��� �ݺ��� �����ڴ� �ڽ��� � �ݺ������� �ܺο� �˷��� �մϴ�.
template<typename T> class slist_iterator
{
public:
	typedef forward_iterator_tag iterator_category;
	// ++, * ���� ����.
};
template<typename T> class vector_iterator
{
public:
	typedef random_access_iterator_tag iterator_category;
	// ++, * ���� ����.
};
*/
template<typename T> void xadvance_imp(T& p, int n, input_iterator_tag)
{
	while (n--)++p;
}

template<typename T> void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	p = p + n;
}

// ��� �ݺ��ڸ� n ��ŭ �����ϴ� �Ϲ�ȭ �Լ�
template<typename T> void xadvance(T& p, int n) // n > 0 �϶��� ����մϴ�.
{
	xadvance_imp(p, n, typename T::iterator_category()); // Ÿ�Ը��̹Ƿ� ��ü�� �ѱ�� ���� () �� ��üȭ ��Ų��.
//	p = p + n;
//	while(n--) ++p; // �׷��� ���� �������ٹݺ��ڶ�� �̳��� �ʹ� �������ϰ� ũ��!
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	vector<int>::iterator p = v.begin();

	xadvance(p, 5); // p�� 5ĭ �����ϴ� �Լ�
	
	cout << *p << endl;
}