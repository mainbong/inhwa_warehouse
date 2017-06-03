// 3_hash
#include "show.h"
#include <set> // RB Tree
#include <unordered_set> // hash

int main()
{
	hash<int> hi; // 해쉬 함수( 함수 객체로 되어 있습니다. )

	cout << hi(10) << endl;
	cout << hi(20) << endl;
	cout << hi(10) << endl;
	
	// 문자열의 해쉬 함수를 사용해 보세요
	hash<string> hs;
	cout << hs("hello") << endl;
	cout << hs("abcd") << endl;

	cout << hash<double>()(3.4) << endl; // 이런표현도 알아주세요
}