// 9_완벽한전달자14
#include <iostream>
using namespace std;

// 싱글톤 : 오직 한개의 객체만 만드는 클래스
// CRTP : 부모가 템플릿인데 자식이 상속받으면서 자신의 이름을 부모에 
//		  템플릿인자로 알려주는 기법 - 안드로이드 싱글톤의 원리!!
template<typename T> class Singleton
{
public:
	template<typename ... Types>
	static T& getInstance(Types&& ... args)
	{
		static T s(forward<Types>(args)...);
		return s;
	}
};
// Cursor도 싱글톤으로 하고 싶습니다.
class Cursor : public Singleton<Cursor>
{
public:
	Cursor(int a, int b) {}
};

int main()
{
	Cursor& s = Cursor::getInstance(10, 20);
}





