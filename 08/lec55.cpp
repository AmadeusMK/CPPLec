#include "lec55.h"

using namespace std;  //  std:: 생략가능

class MyClass {
  public:
    void PrintThis() {
      cout << "나의 주소는 : " << this << endl;
    }
};

//  55. this 포인터
void lec55() {

  title_header( "55. this 포인터" );

  MyClass a, b;

  cout << "a 의 주소 : " << &a << endl;
  cout << "b 의 주소 : " << &b << endl;

  a.PrintThis();
  b.PrintThis();
}