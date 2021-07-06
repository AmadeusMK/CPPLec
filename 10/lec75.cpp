#include "lec75.h"

using namespace std;  //  std:: 생략가능

/*
  접근 제어
  public    : 외부접근 O / 자식클래스 O
  protected : 외부접근 X / 자식클래스 O
  private   : 외부접근 X / 자식클래스 X
*/

//  부모 class
class Base {

  public:
    void bFunc() {
      cout << "Hello!" << endl;
    }

    int bNum;

    int bPublic;

  protected:
    int bProtected;

  private:
    int bPrivate;
};

//  자식(파생) class
//  부모 class 를 public 으로 상속함
//  protected Base 로 상속을 받을 경우, public 은 protected 로 상속 됨
//  private Base 로 상속 받을 경우, public, protected 는 private 로 상속 됨
class Derived : public Base {

  public:
    void dFunc() {
      cout << "Hello?" << endl;

      //  접근제한자 확인
      bPublic    = 11;
      bProtected = 22;
      // bPrivate   = 33;  //  부모 class 의 private 멤버 접근 불가

      dPublic    = 111;
      dProtected = 222;
      dPrivate   = 333;
    }

    int dNum;

    int dPublic;

  protected:
    int dProtected;

  private:
    int dPrivate;
};

//  75. 상속과 접근 제어
void lec75() {

  title_header( "75. 상속과 접근 제어" );

  lec75_1();

  lec75_2();
}

void lec75_1() {

  title_header( "상속" );

  Base b;
  Derived d;

  b.bFunc();
  b.bNum = 1;

  cout << b.bNum << endl;

  d.bFunc();

  cout << d.bNum << endl;

  d.bNum = 2;

  cout << d.bNum << endl;

  d.dFunc();
  d.dNum = 3;

  cout << d.dNum << endl;

}

void lec75_2() {

  title_header( "접근 제어" );

  Base b;
  Derived d;

  b.bPublic    = 1;
  // b.bProtected = 2;   //  외부에서 protected 멤버 접근 불가
  // b.bPrivate   = 3;   //  외부에서 private 멤버 접근 불가

  d.bPublic    = 11;  //  public 으로 상속 받음
  // d.bProtected = 22;  //  외부에서 protected 멤버 접근 불가
  // d.bProtected = 33;  //  외부에서 private 멤버 접근 불가

  d.dPublic    = 111;
  // d.dProtected = 222; //  외부에서 protected 멤버 접근 불가
  // d.dPrivate   = 333; //  외부에서 private 멤버 접근 불가
}