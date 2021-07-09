#include "lec89.h"

using namespace std;  //  std:: 생략가능

/*
  struct  모든 멤버가 기본적으로 public 
  class   별도로 지정 하지 않을 경우, 모든 멤버는 private

  다중상속은 여러 문제가 발생 함으로, 인터페이스로부터만 받는다.

  인터페이스    : 모든 메서드가 순수 가상 함수이고, (비정적)멤버 변수는 없는 클래스
  추상 클래스   : 순수 가상 함수가 하나 이상 들어 있는 클래스
  다형적 클래스 : 가상 함수가 하나 이상 들어 있는 클래스
*/

//  89. 다중 상속과 다이아몬드 문제
void lec89() {

  title_header( "89. 다중 상속과 다이아몬드 문제" );

  //  이상한 상황
  lec89_1();

  //  다이아몬드 문제와 가상 상속
  lec89_2();

  //  오버라이딩으로 인해 문제 발생
  lec89_3();

  //  인터페이스로 부터 상속
  lec89_4();
}

/*  --------------------------------------------------------------------------------  */

//  다이아몬드 문제

struct Person1 {
  int age;
  void Eat() {
    cout << "먹는다..." << endl;
  }
};

struct Student1 : Person1 {
  void Study() {
    cout << "공부한다..." << endl;
  }
};

struct Worker1 : Person1 {
  void Work() {
    cout << "일한다..." << endl;
  }
};

struct Researcher1 : Student1, Worker1 {};

void lec89_1() {

  title_header( "이상한 상황" );

  Researcher1 r;

  r.Study();
  r.Work();

  //  이상한 상황...
  r.Student1::Eat();
  r.Worker1::Eat();

  //  정말 이상한 상황...
  r.Student1::age = 10;
  r.Worker1::age  = 20;
}

/*  --------------------------------------------------------------------------------  */

//  Person 에 virtual 소멸자 추가. 다형적 클래스가 됨
//  다이아몬드 문제 발생  <=  가상상속으로 해결

struct Person2 {
  int age;
  void Eat() {
    cout << "먹는다..." << endl;
  }
  virtual ~Person2() {}  //  다형적 클래스

};

struct Student2 : virtual Person2 {   //  가상 상속
  void Study() {
    cout << "공부한다..." << endl;
  }
};

struct Worker2 : virtual Person2 {    //  가상 상속
  void Work() {
    cout << "일한다..." << endl;
  }
};

struct Researcher2 : Student2, Worker2 {};

void lec89_2() {

  title_header( "다이아몬드 문제와 가상 상속" );

  Person2 *p = new Researcher2;   //  다형성...

  //  Person2 으로 부터 직접 상속
  p->Eat();
  p->age = 10;

  delete p;
}

/*  --------------------------------------------------------------------------------  */

struct Person3 {
  int age;
  void Eat() {
    cout << "먹는다..." << endl;
  }
  virtual ~Person3() {}

};

struct Student3 : virtual Person3 {
  void Eat() {    //  오버라이딩 함...
    cout << "냠냠..." << endl;
  }
  void Study() {
    cout << "공부한다..." << endl;
  }
};

struct Worker3 : virtual Person3 {
  void Eat() {    //  오버라이딩 함...
    cout << "쩝쩝..." << endl;
  }
  void Work() {
    cout << "일한다..." << endl;
  }
};

struct Researcher3 : Student3, Worker3 {};

//  
void lec89_3() {

  title_header( "오버라이딩으로 인해 문제 발생..." );

  Researcher3 r;

  // r.Eat();  //  오버라이딩으로 인해 문제 발생...
}

/*  --------------------------------------------------------------------------------  */

//  인터페이스    : 모든 메서드가 순수 가상 함수이고, (비정적)멤버 변수는 없는 클래스

struct IPerson {   //  인터페이스
  virtual ~IPerson() {}
  virtual void Eat() = 0;
  virtual int GetAge() = 0;   //  멤버변수는 선언 할 수 없음으로, 조회 할 방법은 선언 해 둠...
};

struct IStudent : virtual IPerson {   //  인터페이스(IStudent)는 가상상속을 해야 함
  virtual void Study() = 0;
};

struct Student4 : virtual IStudent {   //  인터페이스(IStudent)는 가상상속을 해야 함
  void Eat() {    //  오버라이딩 함...
    cout << "냠냠..." << endl;
  }
  void Study() {
    cout << "공부한다..." << endl;
  }
  int age = 20;
  int GetAge() { return age;}
};

struct IWorker : virtual IPerson {    //  인터페이스(IWorker)는 가상상속을 해야 함
  virtual void Work() = 0;
};

struct Researcher4 : IStudent, IWorker {
  void Eat() {
    cout << "먹는다..." << endl;
  }
  void Study() {
    cout << "공부한다..." << endl;
  }
  void Work() {
    cout << "일한다..." << endl;
  }
  int age = 10;
  int GetAge() { return age;}
};

//  
void lec89_4() {

  title_header( "인터페이스 사용" );

  Researcher4 r;

  r.Eat();
  r.Study();
  r.Work();
  r.GetAge();

  IPerson *p = new Researcher4;

  p->Eat();
  cout << p->GetAge() << endl;

  delete p;

  p = new Student4;

  p->Eat();
  cout << p->GetAge() << endl;

  delete p;
}
