#include "show.h"
#include <fstream> // 파일입출력

// 켄테이너를 담는 컨테이너가 좋을때가 많습니다.

bool foo(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	ifstream fin("3_컨테이너8.cpp"); // 현재 소스이름 넣으세요.

	string s;

	vector<string> v;
	while (getline(fin, s))// fin 에서 한줄 꺼내기
		v.push_back(s);

	//---------------------------------------
	//reverse( v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		//reverse(v[i].begin(), v[i].end());
		//replace(v[i].begin(), v[i].end(), 'i', ' ');

		// 모든 모음을 공백으로
		replace_if(v[i].begin(), v[i].end(), foo, ' ');
	}
	//---------------------------------------

	for (int i = 0; i < v.size();i++)
		cout << v[i] << endl;
}