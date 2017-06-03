#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>
#include <algorithm> // find() 같은 함수가 이 헤더에 있습니다.
using namespace std; // 흔히 "알고리즘" 이라고 합니다.

					 // 모든 컨테이너의 요소를 출력하는 함수
template<typename T> void show(T& c)
{
	typename T::iterator p = c.begin();
	while (p != c.end())
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}