#include <iostream>
#include <math.h>

class complex
{
  public:
    complex(double r, double i) : r{r}, i{i} {}
    // complex(double r) : complex{r, 0.0} {}
    // complex() : complex{0.0} {}
    // 다른 생성자를 호출하는것, 초기화에 공을 들인 곳에 효율적
    complex(double r) : r{r} {}
    complex() {}

    // complex(double rn = 0.0, double in = 0.0) : r(rn), i(in) {}
    // complex(const complex& c) : r(c.r), i(c.i) {}

    // ~complex() {  }
  
    complex& operator= (const complex& c) 
    {
	r= c.r; i= c.i;
	return *this;
    }

    // 복사 배정: 암묵적 변환 - 명시적으로 정의하는게 좋다
    complex& operator= (double rn) 
    {
	r= rn; i= 0.0;
	return *this; // this는 객체 자기 자신을 가리키는 포인터, 반환 타입 확인
    }

    // complex operator+(const complex& c2) const
    // {
    //     std::cout << " -- c+c -- "; 
    //     return complex(r + c2.r, i + c2.i);
    // }

    // complex operator-() const { return complex(-r, -i); }

    complex operator+(double d) const;
  
    friend inline double const& real(const complex& c) { return c.r; } 
    friend inline double& real(complex& c) { return c.r; } 

    friend inline double const& imag(const complex& c) { return c.i; } 
    friend inline double& imag(complex& c) { return c.i; }  

    friend double& dings(complex& c);

    // double const& real() const { return r; } // c
    // double& real() { return r; }      // m

    // double const& imag() const { return i; } // c
    // double& imag() { return i; }      // m

    friend complex operator-(const complex& c1, const complex& c2) // ;
    {
	return {c1.r - c2.r, c1.i - c2.i};
    }

    complex subtract(const complex& c1, const complex& c2){
        return {c1.r - c2.r, c1.i - c2.i};
    }

  private:
    double r= 0.0, i= 0.0;
};

// double& inline dings(complex& c) { return c.r; } // does not compile

inline complex operator+(const complex& c1, const complex& c2)
{
    std::cout << " -- c+c -- "; 
    return complex(real(c1) + real(c2), imag(c1) + imag(c2));
}

inline complex operator+(double d, const complex& c2)
{
    std::cout << " -- d+c -- "; 
    return complex(d + real(c2), imag(c2));
}

inline complex
complex::operator+(double d) const
{
    std::cout << " -- c+d -- "; 
    return complex(r + d, i);
}

// inline complex operator-(const complex& c1, const complex& c2)
// {
//     std::cout << " -- c-c -- "; 
//     return complex(c1.r - c2.r, c1.i - c2.i);
// }

// inline complex operator-(double c1, const complex& c2)
// {
//     std::cout << " -- d-c -- ";     
//     return complex(c1 - c2.real(), -c2.imag());
// }
 
complex operator-(const complex& c1) 
{ std::cout << "free unary -\n"; return complex(-real(c1), -imag(c1)); }


std::ostream& operator<<(std::ostream& os, complex c)
{
    os << '(' << real(c) << ',' << imag(c) << ")";
    return os;
}


struct whatever
{
    operator complex() { return complex(3, 4); }
};

struct something_else
{
    operator whatever() { return whatever(); }
};

double complex_abs(complex c){
    return std::sqrt(real(c) * real(c) + imag(c) * imag(c));
}

int main()
{
    complex c{7.0, 8}, c2= {0, 1}, c3= {9.3}, c4= {c}; // aggregate initialzation
    const complex cc= {c3};
    std::cout << "c = " << c << '\n';
    std::cout << "c2 = " << c2 << '\n';
    std::cout << "c3 = " << c3 << '\n';
    std::cout << "c4 = " << c4 << '\n';
    std::cout << "cc = " << cc << '\n';

    std::cout << "c3 - c2 = " << c3 - c2 << '\n';

    double r2= real(complex(3, 7)) * 2.0;
    std::cout << "r2 = " << r2 << '\n';

    // complex_abs(7.0); // this is error.. in explicit constructor..
    complex_abs(complex{7.0});

    std::cout << c.subtract(c2,c3) << "\n";
    // 이같이 함수의 반환값으로 균일 초기화 사용 가능..

    return 0;
}
