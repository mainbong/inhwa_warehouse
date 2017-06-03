#-*-coding:utf-8-*-
'''
 내장함수 print()는 데이터를 문자열로 변환해 표준 출력 버퍼에 전달
 사용법은 c 표준함수인 printf 와 유사
 출력 대상은 타입에 관계 없이 상수나 변수를 사용하며 2개 이상일 때는 쉼표로 구분
 end 와 sep 인자로 종료나 구분문자 지정 가능
 형식 지정자가 포함된 문자열을 인자로 사용하면 % 기호로 형식 지정자에 대응하는 대상 연결
'''
print(10)
print(3.14, end=" ")
print("Hello World")

print(10, 3.14, "Hello World")
print(10, 3.14, "Hello World", sep=", ")

print("a = %d, b = %f, c = %s"%(10, 3.14, "Hello"))

'''
 내장함수 input() 은 표준입력 버퍼에 저장된 문자열을 읽어와 반환
 C 표준 함수인 gets() 와 유사
 표준 입력버퍼가 빈 상태에서 input() 이 실행되면 사용자가 Enter키를 누를때까지 입력 대기 상태가 됨
 입력된 문자열을 정수로 취급하려면 내장함수 int() 로 변환, float() 로 실수
'''

a = input()
a = input("Yes or No?")
a = int(input("Select Menu: "))

name = input("You'r name?")
old = int(input("old: "))

print("name = %s, old = %d"%(name, old))

# 식별이름
'''
 식별이름은 변수나 함수, 클래스와 같은 프로그램 요소를 고유하게 구분
 일반적인 프로그래밍 언어 규칙과같음
 파이썬은 유니코드를 지원하므로 한글도 가능
 클래스 이름은 CamelCase 로 표기
 const 상수를 지원하지 않으므로 const 의미의 변수는 모두 CAPITAL 로 표기
 변수나 함수는 lower_case 로 표기
 '''

#키워드
'''
 키워드는 의미가 프로그램 전체에 미치므로 식별이름으로 재사용할 수 없는 이름
 객체지향 및 함수형 프로그래밍 지원 키워드 포함
 구조적 예외처리 지원 키워드 포함
 False class finally is return None continue
 for lambda try Trye def from nonlocal
 while and del global not with as
 elif if or yield assert else import
 pass break except in raise
 '''
