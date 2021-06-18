#include "lec60.h"

using namespace std;  //  std:: 생략가능

//  60. 생성자의 다양한 사용 방법
void lec60() {

  title_header( "60. 생성자의 다양한 사용 방법" );

  // constructor_test2();

  constructor_test3();
}

/*
*/
class Complex {

  double real, imag;

  public:

    //  1. 생성자 작성 방식 1

    // Complex() {
    //   real = 0, imag = 0;
    // }

    // Complex( double _real, double _imag ) {
    //   real = _real, imag = _imag;
    // }

    //  2. 생성자 작성 방식 2
    //     Default 매개변수 사용시 기본 생성자 생략

    // Complex( double _real = 0, double _imag = 0 ) {
    //   real = _real, imag = _imag;
    // }

    //  3. 생성자 작성 방식 3

    Complex() : real(0), imag(0) {}

    Complex( double real, double imag ) : real( real ), imag(imag) {}

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

void constructor_test2() {

  title_header( "생성자" );

  Complex c1;
  // Complex c2 = Complex( 1 );   //  2. Default 매개변수 사용시...
  Complex c2 = Complex( 2, 3 );
  Complex c3( 3, 4 );

  cout << "c1 = " << c1.GetReal() << " , " << c1.GetImag() << endl;
  cout << "c2 = " << c2.GetReal() << " , " << c2.GetImag() << endl;
  cout << "c3 = " << c3.GetReal() << " , " << c3.GetImag() << endl;

  //  중괄호 사용...
  Complex c4 = { 4, 5 };
  Complex c5 = Complex{ 5, 6 };
  Complex c6{ 6, 7 };

  cout << "c4 = " << c4.GetReal() << " , " << c4.GetImag() << endl;
  cout << "c5 = " << c5.GetReal() << " , " << c5.GetImag() << endl;
  cout << "c6 = " << c6.GetReal() << " , " << c6.GetImag() << endl;

}

/*
*/
class Time {
  public:
    //  생성자
    Time() : h(0), m(0), s(0) {}
    Time( int _s ) : Time() {                           //  생성자 위임
      s = _s;
    }
    Time( int _m, int _s ) : Time( _s ) {
      m = _m;
    }
    Time( int _h, int _m, int _s ) : Time( _m, _s ) {
      h = _h;
    }

    void printTime() {

      if ( h < 10 ) cout << "0";
      cout << h << ":";

      if ( m < 10 ) cout << "0";
      cout << m << ":";

      if ( s < 10 ) cout << "0";
      cout << s << endl;
    }

  private:
    int h;
    int m;
    int s;
};

void constructor_test3() {

  Time t1;
  Time t2(2);
  Time t3(3,4);
  Time t4(4,5,6);

  cout << "t1 : "; t1.printTime();
  cout << "t2 : "; t2.printTime();
  cout << "t3 : "; t3.printTime();
  cout << "t4 : "; t4.printTime();
}