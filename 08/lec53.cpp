#include "lec53.h"

//using namespace std;  //  std:: 생략가능

int n;  //  전역변수로 선언

void set();

namespace lec53_ns {
  int n;
  void set() {
    // lec53_ns::n = 20;
    n = 20;
  }
}

//  선언만 하고, 구현은 아래에서...
namespace lec53_ns2 {
  int n;        //  변수 선언은 여기서...
  void set();   //  함수 원형만 선언...
  namespace inner {
    int n;
    void set();
  }
}

//  53. 네임스페이스
void lec53() {

  using namespace std;  //  std:: 생략가능

  title_header( "53. 네임스페이스" );

  // ::set();  //  명시적 전역 함수 호출
  set();    //  
  lec53_ns::set();
  lec53_ns2::set();
  lec53_ns2::inner::set();

  cout << ::n << endl;
  cout << lec53_ns::n << endl;
  cout << lec53_ns2::n << endl;
  cout << lec53_ns2::inner::n << endl;

}

void set() {
  n = 10;
}

// //  명시적 전역함수
// void ::set() {
//   ::n = 10;   //  명시적 전역변수
// }

// //  선언은 위에서...
// namespace lec53_ns2 {
//   void set() {
//     // lec53_ns2::n = 30;
//     n = 30;     //  묵시적으로 같은 네임스페이스의 n 
//     ::n = 40;   //  명시적으로 전역변수 n 을 가리킴
//   }
//   namespace inner {
//     void set() {
//       n = 50;
//       ::n = 60;   //  명시적으로 전역변수 n 을 가리킴
//     }
//   }
// }

//  네임스페이스 lec53_ns2 의 함수
void lec53_ns2::set() {
  // lec53_ns2::n = 30;
  n = 30;     //  묵시적으로 같은 네임스페이스의 n 
  ::n = 40;   //  명시적으로 전역변수 n 을 가리킴
}

//  네임스페이스 lec53_ns2 의 함수
void lec53_ns2::inner::set() {
  // lec53_ns2::n = 30;
  n = 50;     //  묵시적으로 같은 네임스페이스의 n 
  ::n = 60;   //  명시적으로 전역변수 n 을 가리킴
}
