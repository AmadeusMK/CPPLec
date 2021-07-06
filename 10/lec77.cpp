#include "lec77.h"

using namespace std;  //  std:: 생략가능

/*
  override : 우선하다...
*/

//  80. 오버라이딩과 정적 바인딩
void lec77() {

  title_header( "77. 오버라이딩과 정적 바인딩" );

  lec77_1();

  lec77_2();
}

class Base {

  public:
    // Base() : a(10) {}
    int a = 10; //  옛날 컴파일러에서 에러날 경우, 아래 생성자 사용

    void Print() {
      cout << "From Base!!!" << endl;
    }

};

class Derived : public Base {

  public:
    // Base() : a(20) {}
    int a = 20; //  옛날 컴파일러에서 에러날 경우, 아래 생성자 사용

    void Print() {
      cout << "From Derived!!!" << endl;
    }

};

void lec77_1() {

  title_header( "오버라이드 테스트" );

  Base b;
  Derived d;

  //  멤버변수
  cout << b.a << endl;
  cout << d.a << endl;

  //   명시적으로 클래스 지정
  cout << d.Base::a << endl;      //  Base 에서 상속 받은 a 출력
  cout << d.Derived::a << endl;

  //  함수 호출
  d.Print();
  d.Base::Print();      //  명시적으로 Base 클래스 지정
  d.Derived::Print();
}

void lec77_2() {

  title_header( "정적 바인딩 테스트" );

  //  동적 할당
  Base *b = new Derived();

  //  Base 타입으로 할당(?) 했음으로, Base::Print() 가 호출 됨
  b->Print(); //  (*b).Print();

  delete b;
}