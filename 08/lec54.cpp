#include "lec54.h"

using namespace std;  //  std:: 생략가능

/*
  클래스(타입) : 특정한 용도를 수행하기 위한 변수와 함수를 모아 둔 틀(자료형)
  클래스 = 자료저장(변수) + 자료처리(함수) + ...

  객체(오브젝트) : 그 틀을 이용하여 찍어낸 개체 ( 변수, 메모리 상의 공간 )

  지시자 : private, protected, public
          접근 제어 지시자를 명시적으로 지정하지 않을 경우
          class 의 경우 private , struct 의 경우 public 이 기본으로 지정 됨
*/

struct TV {

  private:
    bool powerOn;
    int channel;
    int volume;

  public:
    void on() {
      powerOn = true;
      cout << "TV를 켰습니다." << endl;
    }
    void off() {
      powerOn = false;
      cout << "TV를 껏습니다." << endl;
    }
    void setChannel( int cnl ) {
      if ( cnl >= 0 &&  cnl <= 100 ) {
        channel = cnl;
        cout << "채널을 " << cnl << " 로 변경." << endl;
      }
    }
    void setVolume( int vol ) {
      if ( vol >= 0 && vol <= 100 ) {
        volume = vol;
        cout << "볼륨을 " << vol << " 로 변경." << endl;
      }
    }

};

//  54. 클래스 = 구조체??
void lec54() {

  title_header( "54. 클래스 = 구조체??" );

  TV lg;
  // lg.powerOn = true;
  // lg.channel = 10;
  // lg.volume  = 50;
  lg.on();
  lg.setChannel( 10 );
  lg.setVolume( 50 );
  lg.setVolume( 150 );
  lg.setChannel( 110 );
  lg.off();
}