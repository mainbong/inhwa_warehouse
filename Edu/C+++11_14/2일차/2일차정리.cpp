// 오늘의 핵심 

// int&& 의 등장 이유
// 1. Move 생성자
// 2. perfect forwarding

// 아래 2개 함수의 차이점은 ?
// move()    : lvalue를 rvalue로 변환하는 함수
// forward() : lvalue를 lvalue로 rvalue를 rvalue로 캐스팅 한다.
//				rvalue전달 될때 T&& a 는 int&& 이지만 a는 항상 lvalue이므로
//												다시 rvalue가 되게 하는것!

// 임시객체개념.
// rvalue vs lvalue 이야기

// 간단한 문법들 : override, 생성자상속, 위임생성자, constexpr, 

// 내일 : 람다 와 나머지 문법들, C++11라이브러리, xget<> 다시 설명..




