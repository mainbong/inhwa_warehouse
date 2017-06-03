// 1_RawString - 115 page
#include <iostream>
using namespace std;

int main()
{
	// ���� ���ڿ� "\"�� ǥ���Ϸ��� "\\" �ؾ� �Ѵ�.
	//  - ���丮��γ� ���� ǥ���Ļ��� ����������.
	const char* s1 = "C:\\AA\\b.txt";

	// C++11�� RawString ���� - R"( ���ڿ� )"
	const char* s2 = R"(C:\AA\b.txt)";

	cout << s2 << endl;

	// 1. "�� ����ϰ� ������ �׳� ����ϸ� �ȴ�
	const char* s3 = R"(AAA"BBB)";
	cout << s3 << endl;

	const char* s4 = R"(AAA"(BBB)";
	cout << s4 << endl;

	// ������ : ���ڿ� �߰��� )" �� ����ϰ� ������
	//const char* s5 = R"(AAA)"BBB)";
	//cout << s5 << endl;

	// �ذ�å.. ����� ���� ��ū�� �߰��Ѵ�.
	const char* s6 = R"***(AAA)"BBB)***";
	cout << s6 << endl;

}









