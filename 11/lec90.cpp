#include "lec90.h"

using namespace std;  //  std:: 생략가능

/*
  정사각형은 직사각형의 하위 객체이지만, 
  여러 문제들로, 실제 구현은 정사각형을 상속하는 직사각형으로 구현 하기도 함...
*/

//  90. 정사각형-직사각형 문제
void lec90() {

  title_header( "90. 정사각형-직사각형 문제" );

  //  여러가지 문제...
  lec90_1();

  //  불변(immutable)
  lec90_2();
}

/*  --------------------------------------------------------------------------------  */

class Rectangle1 {
  private:
    double x, y;
  public:
    Rectangle1( const double x, const double y ) : x(x), y(y) {}
    void ResizeX( const double f ) { x *= f; }
    void ResizeY( const double f ) { y *= f; }
    double GetX() { return x; }
    double GetY() { return y; }
};

class Square1 : public Rectangle1 {
  public:
    Square1( const double w ) : Rectangle1( w, w ) {};
    void ResizeX( const double f ) = delete;  //  문제가 되는 함수는 
    void ResizeY( const double f ) = delete;  //  삭제 하고...
    void ResizeXY( const double f ) {
      Rectangle1::ResizeX( f );
      Rectangle1::ResizeY( f );
    }
};

void lec90_1() {

  title_header( "메모리 낭비..." );

  Square1 s(10);
  cout << sizeof( s ) << endl;  //  Square1 는 8바이트면 되지만, Rectangle1 을 상속 받음으로, 16바이트가 필요 함


  title_header( "정사각형이 직사각형이 되는 문제..." );

  // s.ResizeX( 2 );   //  정사각형이 직사각형이 되는 문제...
  s.ResizeXY( 2 );  //  상속받은 함수는 삭제 하고, Square1 에 맞는 함수 추가

  cout << s.GetX() << endl;
  cout << s.GetY() << endl;


  title_header( "그래도, 다형성은 어쩔수 없는..." );

  Rectangle1 *r = new Square1( 10 );

  r->ResizeX( 2 );    //  그래도, 정사각형이 직사각형이 되는 문제는 남아 있음......

  cout << r->GetX() << endl;
  cout << r->GetY() << endl;

  delete r;
}

/*  --------------------------------------------------------------------------------  */

//  불면(immutable)

class Rectangle2 {
  private:
    const double x, y;
  public:
    Rectangle2( const double x, const double y ) : x(x), y(y) {}
    Rectangle2 ResizeX( const double f ) { return Rectangle2( x * f, y     ); }
    Rectangle2 ResizeY( const double f ) { return Rectangle2( x    , y * f ); }
    double GetX() { return x; }
    double GetY() { return y; }
};

class Square2 : public Rectangle2 {
  public:
    Square2( const double w ) : Rectangle2( w, w ) {};
};

void lec90_2() {

  title_header( "불변(immutable)" );

  Square2 s(10);

  Rectangle2 r = s.ResizeX( 2 );

  cout << s.GetX() << endl;
  cout << s.GetY() << endl;

  cout << r.GetX() << endl;
  cout << r.GetY() << endl;
}

/*  --------------------------------------------------------------------------------  */
