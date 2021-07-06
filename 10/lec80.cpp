#include "lec80.h"

using namespace std;  //  std:: 생략가능

/*
  //  순수 가상 함수
  virtual void func() = NULL;
  virtual void func() = 0;

  순수 가상 함수를 1개라도 가지고 있는 클래스는 
  추상 클래스이고, 객체를 생성 할 수 없음

*/

const double PI = 3.141592653589793;

class Shape {
  public:
    //  순수 가상 함수 정의
    //  Repl 에서는 NULL 이 안되는듯...
    virtual double GetArea() = 0;
    virtual void Resize( double f ) = 0;
    virtual ~Shape() {}   //  소멸자도 virtual 로 추가해야 함...
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
};

//  80. 순수 가상 함수와 추상 클래스
void lec80() {

  title_header( "80. 순수 가상 함수와 추상 클래스" );

  Shape *shapes[] = {
    new Circle( 10 ),
    new Rectangle( 20, 30 )
  };

  for ( Shape *s : shapes ) {
    cout << s->GetArea() << endl;
    s->Resize( 2 );
    cout << s->GetArea() << endl;
  }

  //  delete
  //  할당된 메모리 해제
  //  이렇게 하면 된다는데... Repl 에서는 안되는듯...
  //  => Shape 에 virtual 소멸자 추가
  //    virtual ~Shape() {}
  for ( Shape *s : shapes ) {
    delete s;
  }
}