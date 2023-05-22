## 배열.
- Segmentation Fault 발생 -> 접근 시 색인의 유효성
- 배열의 크기를 반드시 컴파일 시점에 알아야 한다.
- 그래서 array 형식으로 해결하고 동적 메모리 할당으로 해결할 수 있다.

## 포인터의 용도
- 객체 참조
- 동적 메모리 관리

## 스마트 포인터
- 동적으로 할당해야함
- 복사 불가, 넘겨주는것 가능
- `unique_ptr`은 배열에 특수화 되어있음.
- `shared_ptr`은 복사가 가능, 동시성 구현시 좋음
```c++
double d = 3.14;
unique_ptr<double> dd{&d};
unique_ptr<double> dp{ new double };
unique_ptr<double> ddd{dp};

unique_ptr<double> f() {return unique_ptr<double>{new double};}
f();
```


```c++
std::shared_ptr<double> f() {
    std::shared_ptr<double> p1{ new double };
    auto p2 = std::make_shared<double>();
    auto p3 = p1;
    std::cout << p3.use_count() << "\n";
    return p3; // p1, p3는 main때문에 파괴되지 않음
}

int main() {
    auto t = f();
    std::cout << t.use_count() << "\n";
	
	return 0;
}
```

## 참조
- 기존 객체에 대한 새로운 이름을 도입한다.
- 포인터와 참조의 장단점을 생각해봐라. 참조가 조금 더 안전하긴 하다.
-
```c++
double& ref(double d) {
    double s = d * d;
    return s; // 상한 참조, stale reference
}

double* ptr(double d) {
    double s = d * d;
    return &s; // dangling pointer..
}

int main() {
    
    int i = 10;
    int& j = i;
    j = 3;
    std::cout << i << "  " << j;
    auto ff= ref(3.0);
    auto fff=ptr(2.01);

	return 0;
}
```

## 매크로
- 매크로에는 길고 추한 대문자 이름만 사용하자
-- 아직도 VS는 min / max / major 가 매크로....
- 매크로보단 상수 / inline / constexpr 대안을 사용하자
- include gaurd
- 조건부 컴파일: #if / #else / #elif