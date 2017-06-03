#include "show.h"
#include <bitset>
#include <ctime>

// unique �� ���� �����

template<int N> class URandom
{
	bitset<N> bs;
	bool recycle;
public:
	URandom(bool b = false) : recycle(b)
	{
		bs.set(); //set bit 1
		srand(time(0));
	}

	int operator()()
	{
		if (bs.none()) // ��� 0�ϰ椷
		{
			if (recycle) {
				return -1
			}
		}
		int v = -1;
		while (bs.test(v = rand() % N));
	}
};

int main()
{
	URandom<10> r;
	for (int i = 0; i < 10; i++)
		cout << r() << endl;
}