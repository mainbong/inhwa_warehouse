// 10_스트림

#include <iostream>	// 표준 입출력
#include <fstream>	// 파일 입출력
#include <sstream>	// 메모리(string) 입출력
#include <string>
using namespace std;

int main()
{
	int n = 10;

	cout << "n = " << n << endl;
	ostringstream oss;

	oss << "n = " << n;
	cout << oss.str() << endl;
}

/*
int main()
{
	string s;
	//cin >> s;

	//ifstream fin("10_스트림.cpp");
	//fin >> s; // 파일에서 입력

	istringstream iss("i am a boy");	
	// String Tokenizing 처럼 동작
	while( iss >> s )
		cout << s << endl;
}*/