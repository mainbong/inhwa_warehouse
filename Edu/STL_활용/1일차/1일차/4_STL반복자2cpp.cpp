// 3_STL�����̳�
#include <iostream>
using namespace std;

template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first;// == last ? 0 : first;
}

template<typename T> struct Node
{
	T	  data;
	Node* next;
	Node(const T& a, Node* n) : data(a), next(n) {}
};

// slist �ȿ� �ִ� Node�� ����Ű�� ������ ��Ȱ�� ��ü�� ������

template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	inline slist_iterator(Node<T>* p = 0) : current(p) {}

	// �� ��ü�� ������ ó�� �����ؾ� �մϴ�(++, *, ==, != ������ �ʿ��մϴ�.)

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }

	inline bool operator==(const slist_iterator& it) { return current == it.current; }
	inline bool operator!=(const slist_iterator& it) { return current != it.current; }
};

template<typename T> class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}

	void push_front(const T& a) { head = new Node<T>(a, head); }

	// ��� �����̳� �����ڴ� �ݵ�� �ڽ��� ���۰� ������ ����(0)�� ����Ű��
	// �ݺ��ڸ� �����ϴ� �Լ� 2���� �־�� �Ѵ�.

	// ��� �����̳� �����ڴ� �ڽ��� �ݺ��� �̸��� �̸� ��ӵ� ���·� �ܺο� �˷��� �Ѵ�.
	typedef slist_iterator<T> iterator;
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
};




int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	slist<int>::iterator p2 = xfind(s.begin(), s.end(), 30);
	cout << *p2 << endl; // xfind �����ؼ�, �ҽ� ���� ���ʿ� �ٿ��ֱ� ���ּ���.

	
	slist<int>::iterator p = s.begin(); // ���� p�� �����Ϳ� �����մϴ�.

	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}

