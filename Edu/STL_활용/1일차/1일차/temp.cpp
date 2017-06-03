// 7_스트림반복자
#include "show.h"
#include <iterator>
#include <fstream>

// 4.
int main()
{
	ifstream fin("7_스트림반복자2.cpp");
	ofstream fout("temp.cpp");

	istreambuf_iterator<char> p1(fin), p2;

	ostream_iterator<char> p3(fout, "");

	copy(p1, p2, p3);
}


/*
// 3. 화일과 스트림 반복자
int main()
{
	ifstream fin("7_스트림반복자2.cpp"); // 현재 파일 이름을 넣으세요..

//	istream_iterator<char> p1(fin), p2; // 디폴트 생성자는 EOF 입니다.
	istreambuf_iterator<char> p1(fin), p2; // white space를 포함해서 입력

//	cout << *p1 << endl;
	
	ostream_iterator<char> p3(cout, "");
	
	copy(p1, p2, p3);
}
*/
/*
// 2. 입력 스트림반복자
int main()
{
	istream_iterator<int> p(cin);
	int n = *p;	
	cout << n << endl;
}
*/

/*
int main()
{
	ostream_iterator<int> p(cout, " "); // p는 출력 버퍼를 가르킵니다.

	*p = 10; // cout << 10, 출력 후 자동으로 증가(++p) 되는 특징이 있습니다.
	//++p;
	*p = 20;

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	copy(x, x + 10, p);
}
*/