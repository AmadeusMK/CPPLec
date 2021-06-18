#include "ex66.h"

using namespace std;  //  std:: 생략가능

//  66. 8부(클래스) 종합문제 - 1
void ex66() {

  title_header( "66. 8부(클래스) 종합문제 - 1" );

  //  출력 결과 예상
  // ex66_1();

  //  width , height 크기 제한
  ex66_2();
}

/********************************************************************************/

int ex66_n = 0;
namespace A {
  int ex66_n = 0;
  namespace B {
    void set() { ex66_n = 10; }
    int ex66_n = 0;
  }
}
namespace C {
  void set();
  int ex66_n = 0;
}
void C::set() { ex66_n = 20; }

void ex66_1() {

  using namespace A::B;

  set();
  C::set();

  cout << ::ex66_n << endl;
  cout << A::ex66_n << endl;
  cout << A::B::ex66_n << endl;
  cout << C::ex66_n << endl;
}

/********************************************************************************/

void ex66_2() {

  GameWindow gw1( 800, 600 );
  gw1.PrintWindow();

  GameWindow gw2( 1366, 768 );
  gw2.PrintWindow();

  GameWindow gw3( 1920, 1080 );
  gw3.PrintWindow();
}

GameWindow::GameWindow() : width(800), height(600) {}
GameWindow::GameWindow( const int w, const int h ) { ResizeWindow( w, h ); }

int GameWindow::GetWidth() const  { return width;  }
int GameWindow::GetHeight() const { return height; }

void GameWindow::ResizeWindow( const int w, const int h ) {
  if ( w > 1366 ) {
    width  = 800;
  } else {
    width  = w;
  }
  if ( h > 768  ) {
    height = 600;
  } else {
    height = h;
  }
}
void GameWindow::PrintWindow() const {
  cout << "width = " << width << " , height = " << height << endl;
}

/********************************************************************************/
