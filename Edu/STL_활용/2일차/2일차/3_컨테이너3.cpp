#include "show.h"

int main()
{
	vector<int>	v(10);

	v.resize(5);

	cout << v.size() << endl;		// 5
	cout << v.capacity() << endl;	// 10

	v.push_back(5);

	cout << v.size() << endl;		// 6
	cout << v.capacity() << endl;	// 10

	v.shrink_to_fit();

	cout << v.size() << endl;		// 6
	cout << v.capacity() << endl;	// 6

	v.push_back(1);	// 이순간 메모리 할당이 필요하다면
					// 기존 메모리의 1.5배 할당 ( 단, 컴파일러마다 다를 수 있다 )

	cout << v.size() << endl;		// 7
	cout << v.capacity() << endl;	// ? 9. Buffer를 키울때 기존 크기의 1.5 배 만큼 키운다.

	v.reserve(100); // capacity 만 미리 확보...

	cout << v.size() << endl;		// 7
	cout << v.capacity() << endl;	// 100
}