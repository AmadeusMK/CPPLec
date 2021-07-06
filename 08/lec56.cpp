#include "lec56.h"

using namespace std;  //  std:: 생략가능

/*
  생성자 : 객체가 생성될 때 자동으로 호출되는 함수
  소멸자 : 객체가 소명될 때 자동으로 호출되는 함수
*/

//  56. 객체의 생성과 소멸
void lec56() {

  title_header( "56. 객체의 생성과 소멸" );

  // constructor_destroyer_test();

  //  60강에서 계속...
  constructor_test1();
}

/*
생성자 호출                    <=  globalObj 생성
main() 함수 시작
testLocalObj() 함수 시작
생성자 호출                    <=  localObj 생성
testLocalObj() 함수 종료
소멸자 호출                    <=  localObj 소멸
main() 함수 종료
소멸자 호출                    <=  globalObj 소멸
*/
class MyClass {

  public:
    MyClass() {   //  반환형 없음. 생성자
      cout << "생성자 호출" <<endl;
    }
    ~MyClass() {  //  소멸자
      cout << "소멸자 호출" <<endl;
    }
};

//  전역 으로 선언.
// MyClass globalObj;

void testLocalObj() {
  cout << "testLocalObj() 함수 시작" << endl;
  MyClass localObj;
  cout << "testLocalObj() 함수 종료" << endl;
}

void constructor_destroyer_test() {

  title_header( "생성자, 소멸자 실행 시기" );

  cout << "main() 함수 시작" << endl;

  testLocalObj();

  cout << "main() 함수 종료" << endl;
}

/*
*/
class Complex {

  double real, imag;

  public:

    //  Default 매개변수 사용으로 기본 생성자는 
    // Complex() {
    //   real = 0, imag = 0;
    // }

    Complex( double _real = 0, double _imag = 0 ) {
      real = _real, imag = _imag;
    }

    void SetReal( double _real ) {
      real = _real;
    }
    double GetReal() {
      return real;
    }
    void SetImag( double _imag ) {
      imag = _imag;
    }
    double GetImag() {
      return imag;
    }
};

void constructor_test1() {

  title_header( "생성자" );

  Complex c1;
  Complex c2 = Complex( 1 );
  Complex c3 = Complex( 2, 3 );
  Complex c4( 3, 4 );

  cout << "c1 = " << c1.GetReal() << " , " << c1.GetImag() << endl;
  cout << "c2 = " << c2.GetReal() << " , " << c2.GetImag() << endl;
  cout << "c3 = " << c3.GetReal() << " , " << c3.GetImag() << endl;
  cout << "c4 = " << c4.GetReal() << " , " << c4.GetImag() << endl;

  //  중괄호 사용...
  Complex c5 = { 4, 5 };
  Complex c6 = Complex{ 5, 6 };
  Complex c7{ 6, 7 };

  cout << "c5 = " << c5.GetReal() << " , " << c5.GetImag() << endl;
  cout << "c6 = " << c6.GetReal() << " , " << c6.GetImag() << endl;
  cout << "c7 = " << c7.GetReal() << " , " << c7.GetImag() << endl;

}