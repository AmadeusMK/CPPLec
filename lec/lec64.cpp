#include "lec64.h"

using namespace std;  //  std:: 생략가능

/*
  벡터
  멤버 메서드
  연산자 오버로딩
*/

//  64. 멤버 메서드 활용하기 / 65. 연산자 오버로딩
void lec64() {

  title_header( "64. 멤버 메서드 활용하기 / 65. 연산자 오버로딩" );

  Vector2 a(  2, 3 );
  Vector2 b( -1, 4 );

  cout << a.GetX() << "," << a.GetY() << endl;
  cout << b.GetX() << "," << b.GetY() << endl;

  title_header( "Sum" );

  Vector2 c = Vector2::Sum( a, b );
  cout << "Vector2::Sum( a, b ) = ( " << c.GetX() << " , " << c.GetY() << " )" << endl;

  title_header( "Add" );

  Vector2 d = a.Add( b );
  cout << "a.Add( b ) = ( " << d.GetX() << " , " << d.GetY() << " )" << endl;

  title_header( "연산자 멤버 함수 오버로딩" );

  Vector2 e1 = a + b;
  cout << "a + b = ( " << e1.GetX() << " , " << e1.GetY() << " )" << endl;

  Vector2 e2 = a - b;
  cout << "a - b = ( " << e2.GetX() << " , " << e2.GetY() << " )" << endl;

  Vector2 e3 = a * 5;
  cout << "a * 5 = ( " << e3.GetX() << " , " << e3.GetY() << " )" << endl;

  Vector2 e4 = a / 5;
  cout << "a / 5 = ( " << e4.GetX() << " , " << e4.GetY() << " )" << endl;

  float e5 = a * b;
  cout << "a * b = " << e5 << endl;

  title_header( "비멤버 함수 오버로딩" );

  //  a * 5 는 a.operator*( 5 ) 의미 하며, 
  //  5 * a 는 5.operator*(a) 형식으로 사용할 수 없음으로 
  //  별도의 함수(비멤버 함수)로 정의 해서 연산
  Vector2 f = 5 * a;
  cout << "5 * a = ( " << f.GetX() << " , " << f.GetY() << " )" << endl;
}

//  class 선언과 정의의 분리
Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2( float x, float y ) : x(x), y(y) {}

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }

/*
  Vector2 + Vector2
*/
Vector2 Vector2::Sum( Vector2 a, Vector2 b ) {
  return Vector2( a.x + b.x , a.y + b.y );
}

/*
  자기자신 + Vector2
*/
Vector2 Vector2::Add( const Vector2 rhs ) const {
  return Vector2( x + rhs.x, y + rhs.y );
}

/*
  덧셈 연산자 '+' 오버로딩
  사용시 a + b 형식으로 사용 가능
  Add( rhs ) 호출 해서 처리 함
*/
Vector2 Vector2::operator+( const Vector2 rhs ) const {
  return Add( rhs );
}

//  뺄셈 연산자 '-' 오버로딩
Vector2 Vector2::operator-( const Vector2 rhs ) const {
  return Vector2( x - rhs.x, y - rhs.y );
}

//  곱셈 연산자 '*' 오버로딩
Vector2 Vector2::operator*( const float rhs ) const {
  return Vector2( x * rhs, y * rhs );
}

//  나눗셈 연산자 '/' 오버로딩
Vector2 Vector2::operator/( const float rhs ) const {
  return Vector2( x / rhs, y / rhs );
}

//  Vector2 끼리의 곱셈
float Vector2::operator*( const Vector2 rhs ) const {
  return x + rhs.x + y + rhs.y;
}

//  5 * a 는 5.operator*(a) 형식으로 사용 할 수 없음으로 
//  별도의 함수(비멤버 함수)로 정의 해서 연산
Vector2 operator*( const float a, const Vector2 b ) {
  return Vector2( a * b.GetX(), a * b.GetY() );
}

