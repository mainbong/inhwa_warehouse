// 7_��Ʈ���ݺ���
#include "show.h"
#include <iterator>
#include <fstream>

// 4.
int main()
{
	ifstream fin("7_��Ʈ���ݺ���2.cpp");
	ofstream fout("temp.cpp");

	istreambuf_iterator<char> p1(fin), p2;

	ostream_iterator<char> p3(fout, "");

	copy(p1, p2, p3);
}


/*
// 3. ȭ�ϰ� ��Ʈ�� �ݺ���
int main()
{
	ifstream fin("7_��Ʈ���ݺ���2.cpp"); // ���� ���� �̸��� ��������..

//	istream_iterator<char> p1(fin), p2; // ����Ʈ �����ڴ� EOF �Դϴ�.
	istreambuf_iterator<char> p1(fin), p2; // white space�� �����ؼ� �Է�

//	cout << *p1 << endl;
	
	ostream_iterator<char> p3(cout, "");
	
	copy(p1, p2, p3);
}
*/
/*
// 2. �Է� ��Ʈ���ݺ���
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
	ostream_iterator<int> p(cout, " "); // p�� ��� ���۸� ����ŵ�ϴ�.

	*p = 10; // cout << 10, ��� �� �ڵ����� ����(++p) �Ǵ� Ư¡�� �ֽ��ϴ�.
	//++p;
	*p = 20;

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	copy(x, x + 10, p);
}
*/