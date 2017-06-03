#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>
#include <algorithm> // find() ���� �Լ��� �� ����� �ֽ��ϴ�.
using namespace std; // ���� "�˰���" �̶�� �մϴ�.

					 // ��� �����̳��� ��Ҹ� ����ϴ� �Լ�
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