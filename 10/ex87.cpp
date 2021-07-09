#include "ex87.h"

using namespace std;  //  std:: 생략가능

//  87. 10부 종합문제 1 (상속)
void ex87() {

  title_header( "87. 10부 종합문제 1 (상속)" );

  ex87_1();

  ex87_2();
}

/*  --------------------------------------------------------------------------------  */

class A {
  private:
    int x = 10;
  public:
    virtual int f() { return x; }
    virtual ~A() {}
};

class B : public A {
  private:
    int x = 20;
  public:
    int f() { return x; }
    virtual int g() { return A::f(); }
};

class C : public B {
  private:
    int x = 30;
  public:
    int f() { return x; }
    int g() { return B::f(); }
    virtual int h() { return B::g(); }
};

void ex87_1() {

  title_header( "결과 예측 1" );

  A *ab = new B;
  A *ac = new C;
  B *bc = new C;
  C *cc = new C;

  cout << ab->f() << endl;  //  20

  // cout << ab->g() << endl;  //  불가
  cout << static_cast<B*>(ab)->g() << endl;   //  다운캐스팅으로 오류 수정

  cout << ac->f() << endl;  //  30

  // cout << ac->g() << endl;  //  불가
  if ( C *acc = dynamic_cast<C*>(ac) ) {   //  형변환 시도
    cout << acc->g() << endl;              //  성공한 경우 실행
    // delete acc;   //  하지 않음...
  }

  cout << bc->f() << endl;  //  30
  cout << bc->g() << endl;  //  20
  cout << cc->g() << endl;  //  20
  cout << cc->h() << endl;  //  10

  delete ab;
  delete ac;
  delete bc;
  delete cc;
}

/*  --------------------------------------------------------------------------------  */

const double PI = 3.141592653589793;

class Shape {
  public:
    //  순수 가상 함수 정의
    //  Repl 에서는 NULL 이 안되는듯...
    virtual double GetArea() const = 0;
    virtual void Resize( const double f ) = 0;
    virtual ~Shape() {};

    //  추가 됨
    virtual string GetInfo() const {
      return "도형의 넓이 : " + to_string( GetArea() );
    }
};

class Circle : public Shape {
  private:
    double r;
  public:
    Circle( const double r ) : r(r) {}
    double GetArea() const {
      return PI * r * r;
    }
    void Resize( const double f ) {
      r *= f;
    }
};

class Rectangle : public Shape {
  private:
    double a, b;
  public:
    Rectangle( const double a, const double b ) : a(a), b(b) {}
    double GetArea() const {
      return a * b;
    }
    void Resize( const double f ) {
      a *= f;
      b *= f;
    }
    double GetDiag() const {
      return sqrt( a*a + b*b );
    }

    //  추가 됨
    string GetInfo() const {
      return Shape::GetInfo() + "\n" + "대각선 길이 : " + to_string( GetDiag() );
    }
};

void ex87_2() {

  title_header( "도형의 정보 출력" );

  Shape *shapes[] = {
    new Circle( 1 ),
    new Rectangle( 1, 2 )
  };

  for ( Shape *s : shapes ) {

    //  AS-IS : 사각형일 경우, 대각선의 길이를 출력 하기 위해 dynamic_cast 함
    //          클래스를 사용 하는 사람이 클래스의 타입에 따라, 정보를 가공
    // cout << "도형의 넓이 : " << s->GetArea() << endl;
    // if ( Rectangle *r = dynamic_cast<Rectangle*>(s) ) {
    //   cout << "대각선 길이 : " << r->GetDiag() << endl;
    //   // delete r;   //  하지 않음...
    // }

    //  TO-BE : GetInfo() 함수를 통해 출력
    //          dynamic_cast 를 사용하지 않고 도형의 정보 출력
    //          클래스를 설계한 사람이 처리
    cout << s->GetInfo() << endl;

    delete s;
  }


}
