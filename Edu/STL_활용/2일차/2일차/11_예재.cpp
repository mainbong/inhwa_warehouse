#include "show.h"
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	//map<People, list<Tape>> Rental;

	ifstream fin("readme.txt"); // �ϳ� ���ؼ� ���� ���丮�� ��������.

	string s;
	int line = 0;

	typedef map<string, list<int>> IndexMap; // �� �ڷᱸ�� �� �����غ�����.

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

	// MAP �� ���� ���
	ostream_iterator<int> out(cout, ", ");

	IndexMap::iterator p = index.begin();

	while (p != index.end())
	{
		cout << p->first << " : "; // �ܾ� ����� ������
		copy(p->second.begin(), p->second.end(), out);
		cout << endl;
		++p;
	}
}