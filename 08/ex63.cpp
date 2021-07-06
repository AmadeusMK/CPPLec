#include "ex63.h"

using namespace std;  //  std:: 생략가능

//  63. 8부(클래스) 종합문제 - 1
void ex63() {

  title_header( "63. 8부(클래스) 종합문제 - 1" );

  //  출력 결과 예상
  // ex63_1();

  //  width , height 크기 제한
  ex63_2();
}

/********************************************************************************/

int ex63_n = 0;
namespace A {
  int ex63_n = 0;
  namespace B {
    void set() { ex63_n = 10; }
    int ex63_n = 0;
  }
}
namespace C {
  void set();
  int ex63_n = 0;
}
void C::set() { ex63_n = 20; }

void ex63_1() {

  using namespace A::B;

  set();
  C::set();

  cout << ::ex63_n << endl;
  cout << A::ex63_n << endl;
  cout << A::B::ex63_n << endl;
  cout << C::ex63_n << endl;
}

/********************************************************************************/

void ex63_2() {

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
