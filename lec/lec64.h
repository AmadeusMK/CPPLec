#include <iostream>
#include "../util/utils.h"

//  64. 멤버 메서드 활용하기 / 65. 연산자 오버로딩
void lec64();

//  class 선언과 정의의 분리
class Vector2 {

  private:
    float x;
    float y;

  public:
    Vector2();
    Vector2( float x, float y );

    //  Getter 의 경우 멤버변수의 값을 변경 할 수 없도록, const 로 하는게 좋음
    float GetX() const;
    float GetY() const;

    /*
      Vector2 + Vector2
    */
    static Vector2 Sum( Vector2 , Vector2 );

    /*
      자기자신 + Vector2
    */
    Vector2 Add( const Vector2 ) const;

    /*
      덧셈 연산자 '+' 오버로딩
      사용시 a + b 형식으로 사용 가능
      Add( rhs ) 호출 해서 처리 함
    */
    //  Vector2 + Vector2
    Vector2 operator+( const Vector2 ) const;

    //  뺄셈 연산자 '-' 오버로딩
    //  Vector2 - Vector2
    Vector2 operator-( const Vector2 ) const;

    //  곱셈 연산자 '*' 오버로딩
    //  Vector * 숫자
    Vector2 operator*( const float ) const;

    //  나눗셈 연산자 '/' 오버로딩
    //  Vector / 숫자
    Vector2 operator/( const float ) const;

    //  Vector2 끼리의 곱셈
    //  Vector * Vector2
    float operator*( const Vector2 ) const;
};


//  곱셈 연산자 '*' 오버로딩
//  숫자 * Vector
Vector2 operator*( const float, const Vector2 );