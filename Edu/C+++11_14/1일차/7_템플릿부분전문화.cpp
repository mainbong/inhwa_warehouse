// 7_���ø��κ�����ȭ - 7 page ����~
#include <iostream>
using namespace std;
// primary template
template<typename T> class stack
{
	T* buff;
public:
	void push() { cout << "T" << endl; }
};

// template �κ� ����ȭ(partial specializatioin)
template<typename T> class stack<T*>
{
	T* buff;
public:
	void push() { cout << "T*" << endl; }
};

// template ����ȭ(specialization)
template<> class stack<char*>
{
	char* buff;
public:
	void push() { cout << "char*" << endl; }
};

int main()
{
	stack<int>   s1; s1.push();
	stack<int*>  s2; s2.push();
	stack<char*> s3; s3.push();
}






