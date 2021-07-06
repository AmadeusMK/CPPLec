#include "ex64.h"

using namespace std;  //  std:: 생략가능

//  64. 8부(클래스) 종합문제 - 2
void ex64() {

  title_header( "64. 8부(클래스) 종합문제 - 2" );

  MyClass obj[5];

  cout << "Test #1 : " << endl;

  int len = sizeof( obj ) / sizeof( MyClass );
  for ( int i = 0 ; i < len ; i++ ) {
    obj[i].Check( obj );
  }

  cout << "Test #2 : " << endl;

  for ( MyClass &clz : obj ) {
    clz.Check( obj );
  }

  cout << "cnt = " << MyClass::cnt << endl;
}

/********************************************************************************/

int MyClass::cnt = 0;

MyClass::MyClass() : num( cnt++ ) , ch( '\0' ) {}

void MyClass::Check( MyClass *ptr ) {
  if ( ptr + num == this ) {
    cout << num << endl;
  }
}