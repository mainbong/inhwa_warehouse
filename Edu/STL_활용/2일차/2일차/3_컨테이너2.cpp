// 3_�����̳�2
#include "show.h"

// vector, deque	: �������� �ݺ���
// list				: ����� �ݺ���

// 3�� �����̳��� ������ ���� �����մϴ�.

int main()
{
	// 1.����
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,3);
	vector<int> v14(v3);
	vector<int> v5 = { 1,2,3 }; // C++ 11 ���� ����.
/*
	// 2. ��� �߰�
	v1.push_back(10);
	//v1.push_front(20); // vector �� error
	v1.insert(v1.begin() + 1, 20);

	// 3. ����
	v1.pop_back();
	v1.erase(v1.begin());
	v1.erase(find(v1.begin(), v1.end(), 10), v1.end());

	// 4. ��� ����
	v1.front() = 40;

	// []�� at()�� vector�� deque�� ����.
	v1[0] = 40;
	v1.at(0) = 40;
	*/
	vector<int> v8(10);
	try {
		v8.at(11) = 20;
	}
	catch (out_of_range& e)
	{
		cout << "���� �߻�" << endl;
	}
	for (int i = 0; i < v8.size(); i++)
	{
		v8.at(i) = 0;	// 1. �����ʴ�. i �� �߸��� ��찡 ����.
		v8[i] = 0;		// 2
	}
	
}