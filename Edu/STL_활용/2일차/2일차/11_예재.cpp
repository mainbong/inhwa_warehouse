#include "show.h"
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	//map<People, list<Tape>> Rental;

	ifstream fin("readme.txt"); // 하나 구해서 현재 디렉토리에 놓으세요.

	string s;
	int line = 0;

	typedef map<string, list<int>> IndexMap; // 이 자료구조 잘 생각해보세요.

	IndexMap index;

	while (getline(fin, s))
	{
		++line;
		istringstream iss(s);
		string word;

		while (iss >> word)
		{
			index[word].push_back(line);
		}
	}

	// MAP 의 내용 출력
	ostream_iterator<int> out(cout, ", ");

	IndexMap::iterator p = index.begin();

	while (p != index.end())
	{
		cout << p->first << " : "; // 단어 출력해 보세요
		copy(p->second.begin(), p->second.end(), out);
		cout << endl;
		++p;
	}
}