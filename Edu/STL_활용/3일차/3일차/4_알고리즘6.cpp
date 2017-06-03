#include "show.h"

int main()
{
	vector<int> v = { 1,2,3,4,5 };

	// left shift
	// copy(v.begin() + 1 , v.end(), v.begin());

	// right shift
	//copy(v.begin(), v.end() - 1, v.begin() + 1); // 예전에는 1 1 1 1 1
	//copy_backward(v.begin(), v.end() - 1, v.end());
	//show(v);

	string s = "0123456789";

	do
	{
		cout << s << endl;
	} while (next_permutation(s.begin(), s.end())); // 가능한 모든 조합
}

// www.cppreference.com