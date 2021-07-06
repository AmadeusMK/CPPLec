#include "lec81.h"

using namespace std;  //  std:: 생략가능

/*

*/

//  81. 생성/소멸자 실행 순서와 가상 소멸자
void lec81() {

  title_header( "81. 생성/소멸자 실행 순서와 가상 소멸자" );

  //  생성자, 소멸자 실행 순서 확인

  lec81_1();

  lec81_2();

  lec81_3();
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

/*  --------------------------------------------------------------------------------  */

//  멤버변수를 일반 변수로 선언시...

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

void lec81_1() {

  title_header( "일반 멤버변수 선언" );

  PatBingsoo *p = new PatBingsoo;

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

/*  --------------------------------------------------------------------------------  */

/*  --------------------------------------------------------------------------------  */

//  멤버변수를 포인터로 선언시...

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

void lec81_2() {

  title_header( "멤버변수를 포인터로 선언할 경우" );

  PPatBingsoo *p = new PPatBingsoo;

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

/*  --------------------------------------------------------------------------------  */

/*  --------------------------------------------------------------------------------  */

//  

class VPBingsoo {
  private:
    Ice *ice;
  public:
    VPBingsoo() {
      cout << "VPBingsoo()" << endl;
      ice = new Ice;
    }
    //  부모클래스의 소멸자는 가상 소멸자로 만들어 주는것이 좋음
    virtual ~VPBingsoo() {
      cout << "~VPBingsoo()" << endl;
      delete ice;
    }
};

class VPPatBingsoo : public VPBingsoo {
  private:
    Pat *pat;
  public:
    VPPatBingsoo() {
      cout << "VPPatBingsoo()" << endl;
      pat = new Pat;
    }
    ~VPPatBingsoo() {
      cout << "~VPPatBingsoo()" << endl;
      delete pat;
    }
};

void lec81_3() {

  title_header( "부모클래스로 타입 선언" );

  PBingsoo *p = new PPatBingsoo;

  //  ~PPatBingsoo() 가 호출 되지 않음

  delete p;

  title_header( "부모클래스 소멸자를 가상 소멸자(virtual)로 선언" );

  VPBingsoo *vp = new VPPatBingsoo;

  delete vp;

}

/*
실행 결과 출력:

==============================
부모클래스로 타입 선언
==============================
PBingsoo()
Ice()
PPatBingsoo()
Pat()
~PBingsoo()
~Ice()

==============================
부모클래스 소멸자를 가상 소멸자(virtual)로 선언
==============================
VPBingsoo()
Ice()
VPPatBingsoo()
Pat()
~VPPatBingsoo()
~Pat()
~VPBingsoo()
~Ice()

*/
