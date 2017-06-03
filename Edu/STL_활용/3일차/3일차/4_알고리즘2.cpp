//4_알고리즘
#include "show.h"

using namespace std::placeholders;

// 핵심 1: remove()등의 알고리즘은 컨테이너 자체를 줄이지 않습니다. 리턴값으로 유효범위를 알려줌.
int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,3,10 };
	vector<int> v2(10);

	// 알고리즘의 4가지 변형.
	//vector<int>::iterator p = remove(v.begin(), v.end(), 3); // 상수 버전
	//vector<int>::iterator p = 
	//	remove_if(v.begin(), v.end(), bind(modulus<int>(), _1, 2)); // 조건자 버전, 구식 스타일

	//vector<int>::iterator p =
	//		remove_if(v.begin(), v.end(), [](int a) {return a % 2 == 0;}); // C++11 스타일, 람다사용

	// 알고리즘의 복사 버전. 복사버전은 알고리즘의 성능이 복사와 비슷한 녀석에게만 붙어서 성능향상을 준다.
	// sort 의 경우 copy 와 비교할때 성능사용차이가 월등히 크므로 향상을 기대하기 어렵다 -> sort_copy 는 없다.
	//vector<int>::iterator p = remove_copy(v.begin(), v.end(), v2.begin(), 3);
	//


	vector<int>::iterator p
		= remove_copy_if(v.begin(), v.end(), v2.begin(), [](int a) {return a % 2 == 0;});

	//v.erase(p, v.end());
	v2.erase(p, v2.end());
	show(v);
	show(v2);
}