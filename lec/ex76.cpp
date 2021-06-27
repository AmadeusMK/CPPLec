#include "ex76.h"

using namespace std;  //  std:: 생략가능

/*
*/

//  76. 9부 종합문제 1
void ex76() {

  title_header( "76. 9부 종합문제 1" );

  ex76_0();
  ex76_1();
}

//  출력 결과 예측
void ex76_0() {

  title_header( "출력 결과 예측" );

  char str[] =  "Hello, World!";

  cout << str << endl;    //  Hello, World!

  //  *str = str[0]
  cout << *str << endl;   //  H

}

//  출력 결과 예측
void ex76_1() {

  title_header( "출력 결과 예측" );

  int a = 10, b = 20, c = 30;

  int *p = &a;
  int &r =  b;
  int **pp   = &p;    //  p 라는 포인터를 가리키는 더블 포인터 pp (24강)
  int* (&rp) =  p;    //  p 라는 포인터를 가리키는 레퍼런스 변수 rp (51강)

  r    = c / *p;      //  30 / 10 = 3 이며 r 은 b 의 레퍼런스임으로, b = 3 대입
  rp   = &c;          //  rp 는 p 가 가리키는 주소. c 로 변경. p = &c
  **pp = 40;          //  p 가 가리키는 변수 c = 40 
  *p   = 50;          //  c = 50
  *pp  = &a;          //  p = &a
  *rp  = 60;          //  *p = 60 임으로 a = 60

  cout << "a    = " << a    << endl;  //  60
  cout << "b    = " << b    << endl;  //  3
  cout << "c    = " << c    << endl;  //  50
  cout << "*p   = " << *p   << endl;  //  *p 는 a 의 값 60
  cout << "r    = " << r    << endl;  //  r 은 b 의 레퍼런스 임으로 b 의 값 3
  cout << "**pp = " << **pp << endl;  //  p 가 가리키는 a 의 값 60
  cout << "*rp  = " << *rp  << endl;  //  p 가 가리키는 a 의 값 60
}