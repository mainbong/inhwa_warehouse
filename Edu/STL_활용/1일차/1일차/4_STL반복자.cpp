#include <iostream>
using namespace std;

template <typename T> class slist_iterator
{
	Node<T>* current;
public:
	inline slist_iterator(Node<T>* p = 0) : current(p) {}

	// �� ��ü�� ������ó�� �����ؾ� �մϴ� ( ++, *, ==, != ������ �ʿ��մϴ�.)
	inline slist_iterator& operator++()
	{ 
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }

	inline bool operator==(const slist_iterator& it) { return current == it.current; }
	inline bool operator!=(const slist_iterator& it) { return current != it.current; }
};

