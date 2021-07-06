#include "lec83.h"

using namespace std;  //  std:: 생략가능

/*
  static_cast
  정적 형변환 - 컴파일시 발생
  기본적인 자료형끼리의 변환
  Up/down casting
*/

class Base {
  public:
    int a = 1;
};

class Derived1 : public Base {
  public:
    void f() {
      cout << "Derived1::f()" << endl;
      cout << b << endl;
    }
    float b = 3.14;
};

class Derived2 : public Base {
  public:
    void f() {
      cout << "Derived2::f()" << endl;
      cout << c << endl;
    }
    int c = 4;
};

//  83. 상속에서의 형변환 (2) - 다운캐스팅
void lec83() {

  title_header( "83. 상속에서의 형변환 (2) - 다운캐스팅" );

  Base *b = new Derived1;
  // b->f();     //  불가

  title_header( "다운캐스팅" );

  Derived1 *db = ( Derived1* )b;  //  Down casting
  db->f();    //  가능

  title_header( "다운캐스팅 - 오류" );

  int *a = new int(5);
  Derived1 *da = ( Derived1* )a;  //  오류가 있지만, 컴파일은 가능.
  da->f();    //  실행시 오류 발생, 또는, 비정상 실행

  title_header( "static_cast" );

  //  static_cast 로 컴파일시 확인
  // Derived1 *ds = static_cast<Derived1*>(a);   //  Casting 불가
  Derived1 *ds = static_cast<Derived1*>(b);   //  정상
  ds->f();

  title_header( "static_cast - 오류" );

  Derived2 *d2 = static_cast<Derived2*>(b);   //  Derived1 의 포인터이지만, Derived2 로 형변환
  d2->f();    //  실행시 오류 발생, 또는, 비정상 실행. 3.14 가 저장된 binary 데이터를 int 로 표시한 값이 출력 됨...

  delete b;
}
