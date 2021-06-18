#include "lec61.h"

using namespace std;  //  std:: 생략가능

//  61. 정적 멤버 (1) / 62. 정적 멤버 (2)
void lec61() {

  title_header( "61. 정적 멤버 (1) / 62. 정적 멤버 (2)" );

  mix_color();
}

/*
*/
class Color {

  private:
    float r;
    float g;
    float b;
    int id;

  public:

    //  생성자
    Color() : r(0), g(0), b(0), id(idCounter++) {}
    Color( float r, float g, float b ) : r(r), g(g), b(b), id(idCounter++) {}

    //  함수
    float GetR()  { return r;  }
    float GetG()  { return g;  }
    float GetB()  { return b;  }
    int   GetId() { return id; }

    //  정적 멤버 변수
    static int idCounter;   //  선언과 동시에 초기화 할 수 없음

    //  정적 멤버 함수
    //  private 멤버변수에 직접 접근 가능
    static Color MixColors( Color a, Color b ) {
      return Color ( 
                ( a.r + b.r ) / 2 ,
                ( a.g + b.g ) / 2 ,
                ( a.b + b.b ) / 2 
              );
    }

};

//  Class 내부에서 선언과 동시에 초기화 할 수 없음
//  초기화는 외부에서 해야 함.
int Color::idCounter = 1;

void mix_color() {

  title_header( "색깔 섞기" );

  Color blue( 0, 0, 1 );
  Color red ( 1, 0, 0 );

  Color purple = Color::MixColors( blue, red );

  cout << "r = " << purple.GetR() << " / g = " << purple.GetG() << " / b = " << purple.GetB() << endl;

  title_header( "id" );

  cout << "blue   id = " << blue.GetId()   << endl;
  cout << "red    id = " << red.GetId()    << endl;
  cout << "purple id = " << purple.GetId() << endl;

}