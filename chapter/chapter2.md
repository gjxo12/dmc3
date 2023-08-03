## 클래스

### 적절한 추상을 사용하라! 없다면 구현하라!
### 응용 프로그램 수준에서 수정없이 대상 플랫폼 또는 OS에 대해 가장 효율적인 구현을 선택하게끔 하는게 중요!

- 맴버
  - 데이터: 맴버 변수 / 데이터 맴버 / 필드
  - 함수
  - 형식 정의

- struct
  - ### 새로운 추상은 class로, 기능이 제한적이고 불변식이 없는 데이터 중심적 형식이나 보조 형식은 struct로!!

- friend
  - 최소한으로 쓰자: AUTOSAR에서는 금지함..

- static
  - 단일체 / 싱글톤, 정적 상수 맴버 변수는 컴파일 시점..
  - 정적 메서드는 정적 데이터 맴버에서만 접근하고 호출할수 있다..

- Constructor / Assignment
  - 초기화시 {} 로 해야 현대적, ()은 함수 호출을 연상
```c++
class A
{
public:
    A() {};
};
class solver
{
public:
    solver(int row, int col) : a{a} {} // 이렇게 객체를 바로 넘겨서 초기화 가능
    solver(double r = 0, double i = 0) : num1{ r }, num2{ i }, a{ a } {}
    solver(const solver& copy) : num1{ copy.num1 }, num2{ copy.num2 }, a{ a } {}
private:
    A& a; // 참조로 하면 반드시 생성자에서 초기화가 필요함
    double num1;
    double num2;
};

int main()
{
    solver z1;
    solver z2();
    solver z3{ 4 };
    solver z4 = 4;
    solver z5{ 0,1 };
	return 0;
}
```
- 이동 생성자: "더 빠른 복사"로 간주하지 말기, 이동 후 리소스가 사라지는게 아니라 한 객체에서 다른 객체로 넘긴다.
  - 이동된 객체는 잘 정의된 빈 상태, 유효하지 않은 객체가 클래스 설계에 의해 잘 제거가 되도록
- 소멸자
  - 소멸자 밖으로 예외를 절대로 던지지 말기
  - 클래스에 virtual 함수가 있다면, 소멸자도 반드시 virtual

- 메서드 생성 요약
  - 기본 생성자 / 복사 생성자 / 이동 생성자 / 복사 배정 연산자 / 이동 배정 연산자 / 소멸자
  - delete나 default로 명시적 제어 가능, *특정 메서드를 private에 두기보단 delete로 제거하는게 좋음*
  - 이 6대 연산을 가능한 적게 구현하고 많이 선언해라, 구현하지 않으면 default나 delete로.. 문서화가 필요
