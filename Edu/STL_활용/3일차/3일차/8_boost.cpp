#include "show.h"
#include <boost/any.hpp>
using namespace std;
using namespace boost;

int main()
{
	any a1 = 1;
	any a2 = 3.4;
	any a3 = "hello";

	const char* p = any_cast<const char*>(a3);

	cout << p << endl;
}

// www.boost.org 사이트 열어 놓으세요.