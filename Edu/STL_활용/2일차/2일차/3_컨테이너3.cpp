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

	v.push_back(1);	// �̼��� �޸� �Ҵ��� �ʿ��ϴٸ�
					// ���� �޸��� 1.5�� �Ҵ� ( ��, �����Ϸ����� �ٸ� �� �ִ� )

	cout << v.size() << endl;		// 7
	cout << v.capacity() << endl;	// ? 9. Buffer�� Ű�ﶧ ���� ũ���� 1.5 �� ��ŭ Ű���.

	v.reserve(100); // capacity �� �̸� Ȯ��...

	cout << v.size() << endl;		// 7
	cout << v.capacity() << endl;	// 100
}