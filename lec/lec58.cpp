#include "lec58.h"

using namespace std;  //  std:: 생략가능

class MyClass {
  public:
    void PrintThis() {
      cout << "나의 주소는 : " << this << endl;
    }
};

//  58. this 포인터
void lec58() {

  title_header( "58. this 포인터" );

  MyClass a, b;

  cout << "a 의 주소 : " << &a << endl;
  cout << "b 의 주소 : " << &b << endl;

  a.PrintThis();
  b.PrintThis();
}