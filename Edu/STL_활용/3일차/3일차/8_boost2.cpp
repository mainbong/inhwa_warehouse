#include "show.h"
#include <boost/bimap.hpp>
using namespace std;
using namespace boost;

int main()
{
	bimap<string, string> bm;
	typedef bimap<string, string>::value_type type;

	bm.insert(type("mon", "월요일"));
	bm.insert(type("sun", "일요일"));

	// STL map
	// cout << bm["mon"] << endl;

	// STL 의 맵은 KEY -> VALUE 의 검색만 되지만 BIMAP 은 양방향으로 써치가 다된다.
	cout << bm.left.at("mon") << endl;
	cout << bm.right.at("일요일") << endl;	
}

// www.boost.org 사이트 열어 놓으세요.