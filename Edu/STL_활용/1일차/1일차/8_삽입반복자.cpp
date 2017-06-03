// 8_삽입반복자
#include "show.h"

// 클래스템플릿은 암시적 추론이 되지 않으므로 사용시 복잡해 보인다.

// 암시적 추론이 가능한 함수 템플릿을 사용해서 클래스 템플릿을 생성한다.
/*
template<typename T>
back_insert_iterator<T> back_inserter(T& c)
{
	return back_insert_iterator<T>(c);
}
*/
int main()
{
	int x[5] = { 1,2,3,4,5 };

	list<int> s(5, 0); // 5개를 0으로
	//copy(x, x + 5, s.begin()); // 기존 s 에 덮어쓰기...

	// s 의 끝에 추가하는 방법 3가지
	// 1.push_back() 사용
	for (int i = 0; i < 5; i++)
		s.push_back(x[i]);	

	// 2. 후방삽입 반복자 사용
	//back_insert_iterator<list<int>> p(s); // p는 s의 끝에 추가하는 반복자

	//*p = 30; // s.push_back(30);

	//copy(x, x + 5, p);

	// 3. 후방삽입 반복자를 만드는 함수 사용
	copy(x, x + 5, back_inserter(s));

	show(s);
}

/*
template<typename T> T square(T a) { return a * a; }

// 다음중 쉬운것은 ?
square(3);		// 1 . 컴파일러가 T 결정. 암시적 추론
square<int>(3);	// 2 . 사용자가 T 결정. 명시적 추론
/


list<int> s(5, 3); // ?
*/