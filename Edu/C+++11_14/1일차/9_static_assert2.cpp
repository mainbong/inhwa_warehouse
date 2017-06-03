#include <iostream>
#include <type_traits>
using namespace std;
#pragma pack(1)   // 구조체 정렬을 1로 해달라(padding 하지 말라)
struct Packet
{
	char cmd;
	int  data;
};

// sizeof(Packet) => 8
// 구조체에 padding이 있으면 컴파일을 멈추게 한다.
static_assert(sizeof(char) + sizeof(int) == sizeof(Packet),
			  "Packet has unexpected padding!!");

int main()
{

}