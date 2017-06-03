#include <iostream>
#include <type_traits>
using namespace std;
#pragma pack(1)   // ����ü ������ 1�� �ش޶�(padding ���� ����)
struct Packet
{
	char cmd;
	int  data;
};

// sizeof(Packet) => 8
// ����ü�� padding�� ������ �������� ���߰� �Ѵ�.
static_assert(sizeof(char) + sizeof(int) == sizeof(Packet),
			  "Packet has unexpected padding!!");

int main()
{

}