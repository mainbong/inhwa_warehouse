#include "show.h"
#include <boost/bimap.hpp>
using namespace std;
using namespace boost;

int main()
{
	bimap<string, string> bm;
	typedef bimap<string, string>::value_type type;

	bm.insert(type("mon", "������"));
	bm.insert(type("sun", "�Ͽ���"));

	// STL map
	// cout << bm["mon"] << endl;

	// STL �� ���� KEY -> VALUE �� �˻��� ������ BIMAP �� ��������� ��ġ�� �ٵȴ�.
	cout << bm.left.at("mon") << endl;
	cout << bm.right.at("�Ͽ���") << endl;	
}

// www.boost.org ����Ʈ ���� ��������.