#include <iostream>
#include "../util/utils.h"

using namespace std;  //  std:: 생략가능

//  66. 8부(클래스) 종합문제 - 1
void ex66();

void ex66_1();

class GameWindow {
  private:
    int width, height;
  public:
    GameWindow();
    GameWindow( const int , const int );
    int GetWidth() const;
    int GetHeight() const ;
    void ResizeWindow( const int, const int );
    void PrintWindow() const;
};

void ex66_2();