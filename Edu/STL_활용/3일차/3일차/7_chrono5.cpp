#define _CRT_SECURE_NO_WARNINGS
// 7_chrono
#include "show.h"
#include <chrono>
#include <thread>
using namespace std::chrono;
int main()
{
	// system_clock : ����ð��� ������ ����ϴ� Ŭ����. �����Լ���� �Ǿ��ִ�
	// time_point : �ð��� ���ذ� ����� ī��Ʈ
	//				1970�� 1�� 1�� ���� xxxx�� ���..
	system_clock::time_point tp = system_clock::now();

	nanoseconds nano = tp.time_since_epoch(); // 1970�� 1�� 1�� ���� �����
												// nano ��

	cout << nano.count() << endl;
	hours h = duration_cast<hours>(nano);
	cout << h.count() << endl;

	// time_point => Į���� ���·�..
	time_t t = system_clock::to_time_t(tp); // time_point => time_t ����ü

	string s = ctime(&t); // time_t => string

	cout << s << endl;
}