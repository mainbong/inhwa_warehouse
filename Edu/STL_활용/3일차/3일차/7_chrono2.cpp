// 7_chrono
#include "show.h"
#include <chrono>
using namespace std::chrono;	
int main()
{
	//duration : Ư�� ������ ������ ǥ���ϴ� �ڷᱸ��
	//				10�� => 1�ʰ� 10��
	//				1/1000���� 10000��

	duration<int, ratio<1, 100>> d1(2); // 1/100�� 2�� ��, 2/100
	cout << d1.count() << endl;

	duration<int, ratio<1, 1000> > d2(d1);
	cout << d2.count() << endl;

	/*
	typedef duration<int, ratio<1, 1>> Meter;
	typedef duration<int, ratio<1000, 1>> KiloMeter;
	typedef duration<int, ratio<1, 100>> CentiMeter;
	*/
	typedef duration<int, ratio<1, 1>> Meter;
	typedef duration<int, kilo> KiloMeter;
	typedef duration<int, centi> CentiMeter;

	Meter m(15000);	
	CentiMeter cm(m);	// 15 => 1500 data, �ս� ����. �Ͻ��� ��ȯ ���
	cout << cm.count() << endl;

	//KiloMeter km(m); // error 15 => 0.015 data �ս� ���ɼ��� ������
					// ����� ��ȯ�ؾ� �Ѵ�.
	KiloMeter km = duration_cast<KiloMeter>(m);
	cout << km.count() << endl;

	// TODO �� �ؿ� �� ���� ����
}