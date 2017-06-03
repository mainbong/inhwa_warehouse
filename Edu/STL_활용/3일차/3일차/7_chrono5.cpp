#define _CRT_SECURE_NO_WARNINGS
// 7_chrono
#include "show.h"
#include <chrono>
#include <thread>
using namespace std::chrono;
int main()
{
	// system_clock : 현재시간을 얻을때 사용하는 클래스. 정적함수들로 되어있다
	// time_point : 시각의 기준과 경과된 카운트
	//				1970년 1월 1일 기준 xxxx초 경과..
	system_clock::time_point tp = system_clock::now();

	nanoseconds nano = tp.time_since_epoch(); // 1970년 1월 1일 기준 경과된
												// nano 초

	cout << nano.count() << endl;
	hours h = duration_cast<hours>(nano);
	cout << h.count() << endl;

	// time_point => 칼렌더 형태로..
	time_t t = system_clock::to_time_t(tp); // time_point => time_t 구조체

	string s = ctime(&t); // time_t => string

	cout << s << endl;
}