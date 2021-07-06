#include "lec50.h"

//  50. C++ 스타일 기본 문법
void lec50() {

  title_header( "50. C++ 스타일 기본 문법" );

  title_header( "변수 선언" );

  // int a = 10;     //  일반적인 방법
  int a( 10 );    //  int a = 10; 과 동일햔 표현
  int b( a + 5 );

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  title_header( "레퍼런스 변수" );

  int &p = a;
  p = 20;
  cout << "a = " << a << endl;
  cout << "p = " << p << endl;

  // title_header( "r-value : &&r" );

  title_header( "배열" );

  int arr[10] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

  cout << "arr : ";
  for ( int i = 0 ; i < 10 ; i++ ) {
    cout << arr[i] << " ";
  }
  cout << endl;

  title_header( "범위기반 for 문 - arr 배열 확인" );

  cout << "  n : ";
  for ( int n : arr ) {
    cout << n << " ";
    n++;                //  arr 배열의 값은 바뀌지 않음
  }
  cout << endl;

  title_header( "범위기반 for 문 - reference 변수 사용 값 변경" );

  cout << " &n : ";
  for ( int &n : arr ) {  //  reference 변수. n 대신 &n 
    n++;                //  arr 배열의 값 변경됨
    cout << n << " ";
  }
  cout << endl;

  title_header( "범위기반 for 문 - arr 배열 변경 확인" );

  cout << "  n : ";
  for ( int n : arr ) {
    cout << n << " ";   //  arr 배열의 값이 변경 되어 있음...
  }
  cout << endl;
}

