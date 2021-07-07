#include "ex87.h"

using namespace std;  //  std:: 생략가능

/*
  dynamic_cast
  동적 형변환 - 런타임시 발생
  성능은 좋지 않음

  RTTI( Run Time Type Information/Identification)

  가상함수가 하나라도 포함된 클래스는 다형클래스라고 함

*/

//  87. 10부 종합문제 1 (상속)
void ex87() {

  title_header( "87. 10부 종합문제 1 (상속)" );

  ex87_1();

  // ex87_2();

  // ex87_3();
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
    delete acc;
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



void ex87_2() {

}

/*  --------------------------------------------------------------------------------  */

void ex87_3() {

}

/*  --------------------------------------------------------------------------------  */
