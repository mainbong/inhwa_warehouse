// 7_chrono
#include "show.h"
#include <chrono>
using namespace std::chrono;	
int main()
{
	//duration : 특정 단위의 갯수를 표현하는 자료구조
	//				10초 => 1초가 10개
	//				1/1000초의 10000개

	duration<int, ratio<1, 100>> d1(2); // 1/100이 2개 즉, 2/100
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
	CentiMeter cm(m);	// 15 => 1500 data, 손실 없다. 암시적 변환 허용
	cout << cm.count() << endl;

	//KiloMeter km(m); // error 15 => 0.015 data 손실 가능성이 있으면
					// 명시적 변환해야 한다.
	KiloMeter km = duration_cast<KiloMeter>(m);
	cout << km.count() << endl;

	// TODO 이 밑에 좀 빠짐 ㄷㄷ
}