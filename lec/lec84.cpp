#include "lec84.h"

using namespace std;  //  std:: 생략가능

/*

*/

//  84. 생성/소멸자 실행 순서와 가상 소멸자
void lec84() {

  title_header( "84. 생성/소멸자 실행 순서와 가상 소멸자" );

  lec84_1();

  lec84_2();
}

class Ice {
  public:
    Ice() { cout << "Ice()" << endl; }
    ~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
  public:
    Pat() { cout << "Pat()" << endl; }
    ~Pat() { cout << "~Pat()" << endl; }
};

/*
*/

class Bingsoo {
  private:
    Ice ice;
  public:
    Bingsoo() { cout << "Bingsoo()" << endl; }
    ~Bingsoo() { cout << "~Bingsoo()" << endl; }
};

class PatBingsoo : public Bingsoo {
  private:
    Pat pat;
  public:
    PatBingsoo() { cout << "PatBingsoo()" << endl; }
    ~PatBingsoo() { cout << "~PatBingsoo()" << endl; }
};

//  84. 생성/소멸자 실행 순서와 가상 소멸자
void lec84_1() {

  title_header( "일반 멤버변수 선언" );

  PatBingsoo *p = new PatBingsoo;

  //  생성자, 소멸자 실행 순서

  delete p;
}

/*
실행 결과 출력:
Ice()           <=  PatBingsoo 의 부모클래스 Bingsoo 의, 멤버 변수가 Ice 생성
Bingsoo()       <=  PatBingsoo 의 부모클래스 Bingsoo 생성
Pat()           <=  PatBingsoo 의 멤버 변수 Pat 생성
PatBingsoo()    <=  PatBingsoo 생성
~PatBingsoo()   <=  파생 클래스의 소멸자 호출
~Pat()          <=  파생 클래스의 멤버 변수 소멸
~Bingsoo()      <=  부모 클래스의 소멸자 호출
~Ice()          <=  부모 클래스의 멤버 변수 소멸
*/


class PBingsoo {
  private:
    Ice *ice;
  public:
    PBingsoo() {
      cout << "PBingsoo()" << endl;
      ice = new Ice;
    }
    ~PBingsoo() {
      cout << "~PBingsoo()" << endl;
      delete ice;
    }
};

class PPatBingsoo : public PBingsoo {
  private:
    Pat *pat;
  public:
    PPatBingsoo() {
      cout << "PPatBingsoo()" << endl;
      pat = new Pat;
    }
    ~PPatBingsoo() {
      cout << "~PPatBingsoo()" << endl;
      delete pat;
    }
};

void lec84_2() {

  title_header( "멤버변수를 포인터로 선언할 경우" );

  PPatBingsoo *p = new PPatBingsoo;

  //  생성자, 소멸자 실행 순서

  delete p;

}

/*
실행 결과 출력:
PBingsoo()
Ice()
PPatBingsoo()
Pat()
~PPatBingsoo()
~Pat()
~PBingsoo()
~Ice()
*/