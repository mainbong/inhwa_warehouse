#include <iostream>
#include <string>
#include <complex>
using namespace std;

void foo(const char* s) { cout << "char*" << endl; }  // 1
void foo(string s)      { cout << "string" << endl; } // 2

int main()
{
	foo("hello");  // 1 
	foo("hello"s); // 2

	complex<int> c(3i); // 0, 3i
	cout << c << endl; //0,3
}