//4_�˰���
#include "show.h"

using namespace std::placeholders;

// �ٽ� 1: remove()���� �˰����� �����̳� ��ü�� ������ �ʽ��ϴ�. ���ϰ����� ��ȿ������ �˷���.
int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,3,10 };
	vector<int> v2(10);

	// �˰����� 4���� ����.
	//vector<int>::iterator p = remove(v.begin(), v.end(), 3); // ��� ����
	//vector<int>::iterator p = 
	//	remove_if(v.begin(), v.end(), bind(modulus<int>(), _1, 2)); // ������ ����, ���� ��Ÿ��

	//vector<int>::iterator p =
	//		remove_if(v.begin(), v.end(), [](int a) {return a % 2 == 0;}); // C++11 ��Ÿ��, ���ٻ��

	// �˰����� ���� ����. ��������� �˰����� ������ ����� ����� �༮���Ը� �پ ��������� �ش�.
	// sort �� ��� copy �� ���Ҷ� ���ɻ�����̰� ������ ũ�Ƿ� ����� ����ϱ� ��ƴ� -> sort_copy �� ����.
	//vector<int>::iterator p = remove_copy(v.begin(), v.end(), v2.begin(), 3);
	//


	vector<int>::iterator p
		= remove_copy_if(v.begin(), v.end(), v2.begin(), [](int a) {return a % 2 == 0;});

	//v.erase(p, v.end());
	v2.erase(p, v2.end());
	show(v);
	show(v2);
}