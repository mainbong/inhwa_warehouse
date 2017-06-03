#include <iostream>
using namespace std;
// 17 page - �߿��� ���� �Դϴ�.
void foo(int* p)
{
	for (int i = 0; i < 10000; i++)
		cout << "*";
	cout << endl;
}

// Ư�� �Լ��� ������ �����ϴ� ���۸� ����� ���ô�.
template<typename F, typename T> void logTime(F f, T a)
{
	// �ð��� ����� ����
	f(a); 
	// ���� �ð��� ������.. �ɸ� �ð� ����..
}
int main()
{
	foo(0);    // ok..
	foo(NULL); // ok
//	logTime(foo, 0);    // �Լ�, �Լ�����, error
//	logTime(foo, NULL); // error

	// logTime ���� ���� �Լ��� ����Ϸ��� 0��� nullptr�ۿ� �ȵ˴ϴ�.
	// ����� logTime ��� lockAndCall()�Դϴ� - 17 page
	logTime(foo, nullptr); // ok

}





