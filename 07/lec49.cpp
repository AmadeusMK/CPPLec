#include "lec49.h"

namespace a {
  int n;
}

namespace b {
  int n;
}

//  49. C++ 스타일 입출력
void lec49() {

  title_header( "49. C++ 스타일 입출력" );

  output_test();
  namespace_test();
  input_test();
  string_test();
}

void output_test() {
  // std::cout << "Hello World!\n";
  std::cout << "Hello World!" << std::endl;
}

void namespace_test() {

  /*
    'using namespace std;' 를 선언 했음으로, 
    'std::' 생략가능
  */
  cout << "Hello World!" << endl;

  //  namespace 가 다름
  a::n = 10;
  b::n = 20;

  //  
  std::cout << a::n << std::endl;

}

void input_test() {

  int a, b;

  cout << "2개의 숫자를 입력 하세요." << endl;
  cin >> a >> b;   // std::cin 입력받는 자료형은 알아서 처리 함

  cout << a << " + " << b << " = " << a + b << endl;
}

void string_test() {

  string str;   //  크기를 설정하지 않아도 됨.

  str = "Hello, World~!";

  cout << str << endl;

  string myname;

  cout << "이름을 입력 하세요." << endl;
  cin >> myname;

  string message = "이름은 " + myname + " 입나다.";
  cout << message << endl;
}

