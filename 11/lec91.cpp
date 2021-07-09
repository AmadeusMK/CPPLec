#include "lec91.h"

using namespace std;  //  std:: 생략가능

/*
  함수 템플릿
  클래스 탬플릿
*/

//  91. 템플릿 (1) - 함수 템플릿과 클래스 템플릿
void lec91() {

  title_header( "91. 템플릿 (1) - 함수 템플릿과 클래스 템플릿" );

  //  함수 템플릿
  lec91_1();

  //  클래스 템플릿
  lec91_2();

}

/*  --------------------------------------------------------------------------------  */

//  함수 템플릿

//  새로운 함수가 자동으로 생성되어 실행 됨
template<typename T>
T getArraySum( const T arr[], int len ) {
  T sum = T();    //  기본 생성자로 초기화
  for ( int i = 0 ; i < len ; i++ ) {
    sum += arr[i];
  }
  return sum;
}

void lec91_1() {

  title_header( "함수 템플릿" );

  int len = 0;

  int   arr[]  = { 3, 1, 4, 1, 5 };
  float farr[] = { 3.1, 1.2, 4.3, 1.4, 5.5 };
  string  sarr[] = { "Hello, ", "World", "~!!!" };

  //  템플릿 함수 사용
  int   sum  = getArraySum<int  >( arr , sizeof( arr  ) / sizeof( arr[0]  ) );
  float fsum = getArraySum<float>( farr, sizeof( farr ) / sizeof( farr[0] ) );
  string  ssum = getArraySum<string>(  sarr, sizeof( sarr ) / sizeof( sarr[0] ) );

  cout << sum  << endl;
  cout << fsum << endl;
  cout << ssum << endl;
}

/*  --------------------------------------------------------------------------------  */

//  클래스 템플릿

//  typename 이 타입으로...
template<typename T>
class Vector2 {
  private:
    T x, y;
  public:
    Vector2<T>() : x(0), y(0) {}
    Vector2<T>( const T x, const T y ) : x(x), y(y) {}
    T GetX() const { return x; }
    T GetY() const { return y; }
    //  += 연산자 오버라이딩
    Vector2 &operator+=( const Vector2<T> &rhs ) {
      x += rhs.x;
      y += rhs.y;
      return *this;
    }
};

void lec91_2() {

  title_header( "클래스 템플릿" );

  int len = 0;

  Vector2<int> iarr[] = { Vector2<int>( 1, 2 ), Vector2<int>( 3, 4 ), Vector2<int>( 5, 6 ) };
  Vector2<double> farr[] = { Vector2<double>( 1.0, 2.0 ), Vector2<double>( 3.0, 4.0 ), Vector2<double>( 5.0, 6.0 ) };

  // cout << sizeof( iarr[0] ) << endl;  //  8   int(4Byte) 2개...
  // cout << sizeof( farr[0] ) << endl;  //  16  double(8Byte) 2개...

  //  템플릿 함수 사용
  Vector2<int  > isum = getArraySum<Vector2<int  >>( iarr, sizeof( iarr ) / sizeof( iarr[0] ) );
  Vector2<double> fsum = getArraySum<Vector2<double>>( farr, sizeof( farr ) / sizeof( farr[0] ) );

  cout << "( " << isum.GetX() << " , " << isum.GetY() << " )" << endl;
  cout << "( " << fsum.GetX() << " , " << fsum.GetY() << " )" << endl;
}

/*  --------------------------------------------------------------------------------  */
