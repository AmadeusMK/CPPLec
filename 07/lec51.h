#include <iostream>
#include "../util/utils.h"

using namespace std;  //  std:: 생략가능

//  54. C++ 스타일 함수
void lec54();

void overload_test1();

//  AS-IS : 호출 인자의 자료형 별로 함수명을 다르게 하여 각각 만듦...
void myswapi( int &, int & );
void myswapd( double &, double & );
void myswapp( int *&, int *& );

//  TO-BE : 동인한 함수 명으로 Overload
void myswap( int &, int & );
void myswap( double &, double & );
void myswap( int *&, int *& );

//  Overload 2
void overload_test2();

//  기본값 사용으로 생략 가능
void getItem( int );            //  생략
void getItem( int, int );       //  생략
void getItem( int, int, int );  //  기본값 지정
