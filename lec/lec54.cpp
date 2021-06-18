#include "lec54.h"

//  54. C++ 스타일 함수
void lec54() {

  title_header( "54. C++ 스타일 함수" );

  //  iostream 에 swap 함수가 이미 있음

  // overload_test1();
  overload_test2();
}

int inventory[5] = { 0 };
int score = 0;

void overload_test2() {

  title_header( "Overload 2" );

  getItem( 1 );
  getItem( 2, 2 );
  getItem( 3, 3, 3 );

  cout << "score = " << score << endl;
  for ( int i = 0 ; i < 5 ; i++ ) {
    cout << "inventory[" << i << "] = " << inventory[i] << endl;
  }
}

void getItem( int itemId ) {            //  생략 가능
  inventory[itemId]++;
}

void getItem( int itemId, int cnt ) {   //  생략 가능
  inventory[itemId] += cnt;
}

//  기본값이 없을 경우, 필수 파라미터이며, 기본값 지정은 우측 끝부터...
void getItem( int itemId, int cnt = 1, int sc = 0 ) {   //  기본값 지정
  inventory[itemId] += cnt;
  score += sc;
}

void overload_test1() {

  title_header( "Overload 1" );

  int a = 3, b = 5;
  cout << "a = " << a << " / " << "b = " << b << endl;
  myswapi( a, b );
  cout << "a = " << a << " / " << "b = " << b << endl;
  //  overload 한 함수 사용
  myswap( a, b );
  cout << "a = " << a << " / " << "b = " << b << endl;

  double da = 3.333, db = 5.555;
  cout << "da = " << da << " / " << "db = " << db << endl;
  myswapd( da, db );
  cout << "da = " << da << " / " << "db = " << db << endl;
  //  overload 한 함수 사용
  myswap( da, db );
  cout << "da = " << da << " / " << "db = " << db << endl;

  int *pa = &a, *pb = &b;
  cout << "pa = " << pa << " / " << "pb = " << pb << endl;
  cout << "*pa = " << *pa << " / " << "*pb = " << *pb << endl;
  myswapp( pa, pb );
  cout << "pa = " << pa << " / " << "pb = " << pb << endl;
  cout << "*pa = " << *pa << " / " << "*pb = " << *pb << endl;
  //  overload 한 함수 사용
  myswap( pa, pb );
  cout << "pa = " << pa << " / " << "pb = " << pb << endl;
  cout << "*pa = " << *pa << " / " << "*pb = " << *pb << endl;

}

void myswapi( int &a, int &b ) {
  int tmp = a;
  a = b;
  b = tmp;
}

void myswapd( double &a, double &b ) {
  double tmp = a;
  a = b;
  b = tmp;
}

void myswapp( int *(&a), int *(&b) ) {
  int *tmp = a;
  a = b;
  b = tmp;
}

//  overload
void myswap( int &a, int &b ) {
  int tmp = a;
  a = b;
  b = tmp;
}

void myswap( double &a, double &b ) {
  double tmp = a;
  a = b;
  b = tmp;
}

void myswap( int *(&a), int *(&b) ) {
  int *tmp = a;
  a = b;
  b = tmp;
}

