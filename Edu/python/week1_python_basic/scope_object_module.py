#-*-coding:utf-8-*-
# 영역
'''
 영역은 식별이름의 효력이 미치는 범위
 최상위 영역에서 하위 영역으로 계층 구조를 이룸
 최상위에 위치하는 모듈 영역은 C언어의 전역 영역과 동일
 상위 영역에서 하위 영역의 접근은 노출된 이름을 통해 간접적으로 접근
 하위영역에서 상위 영역의 접근은 상황에 따라 다름
'''
# 영역 구분
'''
 하위 영역 시작은 구문 끝에 콜론(:)을 붙이며 들여쓰기 단계에 의해 소속이 구분됨
'''

name = "mi-jung"
age = 18

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def name(self):
        return self.name

    def age(self):
        return self.age

def to_string_list(name, age):
    return ['name=' + name, 'age=' + str(age)]

man = Person(name, age)
print(to_string_list(man.name, man.age))

for i in to_string_list(man.name, man.age):
    print(i.split('=')[1])

# 객체
'''
 파이썬은 모든 것을 객체로 취급
 객체는 자신의 속성과 메소드를 가짐
 속성은 객체의 내부 상태를 나타내는 변수
 메소드는 객체 자신의 고유 연산을 정의한 함수
 다른 객체의 속성에 접근하거나 메소드를 호출하려면 참조 변수나 객체 이름 필요

//객체A
속성
메소드():
    속성 = 20

//객체B
변수 = 객체A
변수.메소드()
변수.속성 = 100
'''

# 모듈
'''
 모듈은 파이썬의 기본 실행 단위로 하나의 파일이 모듈 .py
 모듈은 이름으로 구분되는 변수, 함수, 클래스의 정의를 가짐
 모듈도 하나의 객체이므로 다른 모듈에서 정의한 기능을 사용하려면 import 문으로 모듈 객체 생성 및 참조
 import <모듈>구문은 모듈 이름에 해당하는 파일을(.py확장자 제외) 읽어와 객체로 만든 후 참조 대입
 <모듈>.<이름> 구문으로 해당 모듈에 정의된 이름 사용
 foo.py boo.py 참조
'''
