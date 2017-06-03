
// 7_chrono
#include "show.h"
#include <chrono>
#include <thread>
using namespace std::chrono;
int main()
{
	/*
	typedef duration<int, ratio<1, 1>> seconds;
	typedef duration<int, ratio<60, 1>> minutes;
	typedef duration<int, ratio<3600, 1>> hours;
	*/

	hours h(1);
	minutes m(h);
	seconds s(h);
	nanoseconds ns(h);

	cout << m.count() << endl;
	cout << s.count() << endl;
	cout << ns.count() << endl;

	seconds sec = 1min + 3s;
	sec += 40s;
	cout << sec.count() << endl;

	// sleep
	seconds s3(30);

	//this_thread::sleep_for(s3);
	this_thread::sleep_for(1min + 10s + 5ms);
}