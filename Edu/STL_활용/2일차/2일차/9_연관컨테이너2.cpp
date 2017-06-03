#include "show.h"
#include <map> // pair를 저장하는 set. key값으로 data 보관

int main()
{
	map<string, string> m;

	// 요소 넣기 1.
	pair<string, string> p1("mon", "월요일");
	m.insert(p1);

	m.insert(make_pair("sun", "일요일"));

	// [] 연산자사용
	m["wed"] = "수요일";

	cout << m["wed"] << endl; // 수요일
	cout << m["fri"] << endl; // "fri"가 없을 경우 새롭게 만들게 됩니다.
								// 즉, m.insert(make_pair("fri"), "")

	// 키값을 있는지 조사하려면
	map<string, string>::iterator p = m.find("wed");

	if (p == m.end())
		cout << "tue 가 없습니다." << endl;
	// p 를 사용해서 "wed"와 "수요일"을 출력해보세요.
	// 반복자 : 요소를 가르키는 포인터 역활.
	else
		cout << p->first << "와 " << p->second << endl;
	
}