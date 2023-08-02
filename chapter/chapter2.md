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