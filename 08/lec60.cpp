#include "lec60.h"

using namespace std;  //  std:: 생략가능

/*
  1. 매개변수의 상수화 (모든 함수)
  2. 메서드의 상수화 (멤버 메서드)
*/

//  60. 상수형 매개변수와 상수형 메서드
void lec60() {

  title_header( "60. 상수형 매개변수와 상수형 메서드" );

  account_test();
}

class Account {

  public:
    Account() : money(0) {}
    Account( int money ) : money(money) {
      cout << money << "원 계좌 생성" << endl;
    }

    //  1. 매개변수의 상수화 (모든 함수)
    //     매개 변수로 전달 받은 변수의 값을 함수 내에서 변경 할 수 없도록 함.
    void Deposit( const int d ) {
      // d = 100;  //  매개 변수로 받은 변수의 값은 변경 할 수 없음.
      money += d;
      cout << d << "원 입금" << endl;
    }

    void Draw( const int d ) {
      if ( money >= d ) {
        money -= d;
        cout << d << "원 출금" << endl;
      } else {
        cout << "잔액 부족" << endl;
      }
    }

    //  2. 메서드의 상수화 (멤버 메서드)
    //     함수 내에서, 멤버 변수의 값을 변경 할 수 없도록 함
    int ViewMoney () const {
      return money;
    }

  private:
    int money;
};

void account_test() {

  Account acc( 100 );

  acc.Deposit( 100 );
  acc.Draw( 20 );
  acc.Draw( 100 );
  acc.Draw( 100 );
}