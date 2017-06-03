#define _CRT_SECURE_NO_WARNINGS
// 6_컨테이너와객체복사
#include "show.h"

class People
{
	char* name;
public:
	People(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~People() { delete[] name; }
	
	People(const People& p)
	{
		cout << "복사 생성자 호출" << endl;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};

int main()
{
	People p1("AAA");
	People p2(p1);
	//vector<People> v(10, People("AAA"));
}