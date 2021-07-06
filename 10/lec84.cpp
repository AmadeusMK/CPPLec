#include "lec84.h"

using namespace std;  //  std:: 생략가능

/*
  dynamic_cast
  동적 형변환 - 런타임시 발생
  성능은 좋지 않음

  RTTI( Run Time Type Information/Identification)

  가상함수가 하나라도 포함된 클래스는 다형클래스라고 함

*/

//  84. 상속에서의 형변환 (3) - RTTI 와 dynamic_cast
void lec84() {

  title_header( "84. 상속에서의 형변환 (3) - RTTI 와 dynamic_cast" );

  lec84_1();

  lec84_2();

  lec84_3();
}

/*  --------------------------------------------------------------------------------  */

class Base {
  public:
    int x = 10;
    void f() {}
};

class Derived : public Base {
  public:
    int y = 20;
    void f() {};
};

void lec84_1() {

  title_header( "클래스 크기" );

  // Base *b = new Derived;
  // Derived *d = static_cast<Derived*>(b);

  // b->f();   //  Base::f() 실행됨

  cout << sizeof( Base ) << endl;     //  4   <-  x 의 크기
  cout << sizeof( Derived ) << endl;  //  8   <-  x, y 의 크기

}

/*
결과 출력 :

==============================
클래스 크기
==============================
4
8

*/

/*  --------------------------------------------------------------------------------  */
/*  --------------------------------------------------------------------------------  */

//  가상함수가 하나라도 포함된 클래스는 다형클래스라고 함
class VBase {
  public:
    int x = 30;
    virtual void vf() {};
};

class VDerived : public VBase {
  public:
    int y = 40;
    void vf() {};
};

void lec84_2() {

  title_header( "클래스 크기 - 다형클래스" );

  // Base *b = new Derived;
  // Derived *d = static_cast<Derived*>(b);

  // b->vf();  //  Derived::vf() 실행됨

  cout << sizeof( VBase ) << endl;     //  16 / 8   <-  타입에 대한 정보를 담고 있는, 포인터공간 4바이트 추가
  cout << sizeof( VDerived ) << endl;  //  16 / 12  <-  Repl 에서는 16바이트로 표시...


  title_header( "주소 확인" );

  int *a = ( int* ) new VBase;   //
  cout << a[0] << " / " << a[1] << " / " << a[2] << " / " << a[3] << endl;

  int *b = ( int* ) new VDerived;
  cout << b[0] << " / " << b[1] << " / " << b[2] << " / " << b[3] << endl;

  int *c = ( int* ) new VDerived;
  cout << c[0] << " / " << c[1] << " / " << c[2] << " / " << c[3] << endl;
}

/*
결과 출력 : 

==============================
클래스 크기 - 다형클래스
==============================
16                            <=  윈도에서는 8 ...?
16                            <=  윈도에서는 12...?

==============================
주소 확인
==============================
4205480 / 0 / 30 / 0          <=  VBase
4205528 / 0 / 30 / 40         <=  Derived
4205528 / 0 / 30 / 40         <=  Derived

*/

/*  --------------------------------------------------------------------------------  */
/*  --------------------------------------------------------------------------------  */

const double PI = 3.141592653589793;

class Shape {
  public:
    //  순수 가상 함수 정의
    //  Repl 에서는 NULL 이 안되는듯...
    virtual double GetArea() = 0;
    virtual void Resize( double f ) = 0;
    virtual ~Shape() {};
};

class Circle : public Shape {
  private:
    double r;
  public:
    Circle( double r ) : r(r) {}
    double GetArea() {
      return PI * r * r;
    }
    void Resize( double f ) {
      r *= f;
    }
};

class Rectangle : public Shape {
  private:
    double a, b;
  public:
    Rectangle( double a, double b ) : a(a), b(b) {}
    double GetArea() {
      return a * b;
    }
    void Resize( double f ) {
      a *= f;
      b *= f;
    }
    double GetDiag() const {
      return sqrt( a*a + b*b );
    }
};

void lec84_3() {

  Shape *shapes[] = {
    new Circle( 10 ),
    new Rectangle( 20, 30 )
  };

  for ( Shape *s : shapes ) {
    cout << "도형의 넓이 : " << s->GetArea() << endl;

    // Rectangle *r = static_cast<Rectangle*>(s);  //  성공은 하지만 문제가 있음...
    Rectangle *r = dynamic_cast<Rectangle*>(s); //  Rectangle 로 형변환 시도. 맞지 않을 경우 NULL 리턴

    if ( r != NULL ) {  //  Rectangle 일 경우...
      cout << "대각선 길이 : " << r->GetDiag() << endl;
    }
  }


  //  할당된 메모리 해제
  for ( int i = 0 ; i < 2 ; i++ ) {
    delete shapes[i];
  }

}


/*  --------------------------------------------------------------------------------  */
