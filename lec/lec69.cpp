#include "lec69.h"

using namespace std;  //  std:: 생략가능

/*
  정적 할당 : 프로그램 실행이나, 함수 실행과 동시에 메모리 할당. ex) int a;
  동적 할당 : 프로그램 실행 중에 변수를 메모리에 할당 하는 것. 주로 배열을 동적 할당 함
*/

//  69. 깊은 복사와 얕은 복사 (1)
void lec69() {

  title_header( "69. 깊은 복사와 얕은 복사 (1)" );

  // deep_copy();
}

//  Runtime 시 에러 발생 확인...
void deep_copy() {

  int *a = new int(5);
  int *b = new int(3);

  //  b 를 a 로 복사

  a = b;    //  얕은 복사 ( 참조만 복사 )
  *a = *b;  //  깊은 복사 ( 값을 복시 )

  delete a; //  참조만 복사 했을 경우, a 와 b 는 동일한 주소를 가리키게 됨
  delete b; //  이미 b 가 가리키는 메모리 주소가 해제 되었음으로, 오류 발생 가능
}
