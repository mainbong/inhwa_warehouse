// 3_STL컨테이너
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

// slist 안에 있는 Node를 가르키는 포인터 역활을 객체를 만들자

template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	inline slist_iterator(Node<T>* p = 0) : current(p) {}

	// 이 객체는 포인터 처럼 동작해야 합니다(++, *, ==, != 연산이 필요합니다.)

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

	// 모든 컨테이너 설계자는 반드시 자신의 시작과 마지막 다음(0)을 가르키는
	// 반복자를 리턴하는 함수 2개가 있어야 한다.

	// 모든 컨테이너 설계자는 자신의 반복자 이름을 미리 약속된 형태로 외부에 알려야 한다.
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
	cout << *p2 << endl; // xfind 복사해서, 소스 제일 위쪽에 붙여넣기 해주세요.

	
	slist<int>::iterator p = s.begin(); // 이제 p는 포인터와 유사합니다.

	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}

