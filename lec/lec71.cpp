#include "lec71.h"

using namespace std;  //  std:: 생략가능

/*
  연산자 오버로딩

  String s3;
  s3 = s1;    //  얕은 복사로 진행됨...

  s3.operator=( s1 );   //  연산자 오버로딩으로 해결
*/

class String {

  private:

    char *strData;
    int len;

    //  메모리 공간 할당
    void alloc( int len ) {
      strData = new char[ len + 1 ];  //  길이(len) + 1('\0' 추가)
      cout << "strData 할당 : " << (void*)strData << endl;
    }

    //  할당된 메모리 공간 해제
    void release() {
      delete[] strData;
      cout << "strData 해제 : " << (void*)strData << endl;
    }


  public:

    String() {
      cout << "String()" << endl;
      strData = NULL;
      len = 0;
    }

    String( const char *str ) {
      cout << "String( const char * )" << endl;
      len = strlen( str );
      alloc( len );             //  메모리 공간 할당
      strcpy( strData, str );   //  깊은 복사
    }

    //  복사 생성자 오버로딩
    String( const String &rhs ) {
      cout << "String( const String & )" << endl;
      len = rhs.len;
      alloc( len );             //  메모리 공간 할당
      strcpy( strData, rhs.strData );   //  깊은 복사
    }

    ~String() {
      cout << "~String()" << endl;
      release();                //  할당된 메모리 공간 해제
      strData = NULL;
    }

    //  연산자 오버로딩
    String &operator=( const String &rhs ) {
      cout << "operator=( const String & )" << endl;
      if ( this != &rhs ) { //  인자로 받은 &rhs 와는 의미가 다름...
        len = rhs.len;
        release();              //  기존 할당된 메모리 공간 해제
        alloc( len );           //  메모리 공간 할당
        strcpy( strData, rhs.strData );   //  깊은 복사
      }
      return *this;
    }

    char *GetStrData() const {  //  포인터 리턴
      return strData;
    }

    int GetLen() const {
      return len;
    }

};

//  71. 깊은 복사와 얕은 복사 (3) - 대입 연산자 오버로딩
void lec71() {

  title_header( "71. 깊은 복사와 얕은 복사 (3) - 대입 연산자 오버로딩" );

  String s1( "하이루~" );
  cout << s1.GetLen() << endl;
  cout << s1.GetStrData() << endl;

  // // String s2 = s1;   //  복사 생성자 호출 됨
  // String s2( s1 );   //  복사 생성자 호출 됨
  // cout << s2.GetLen() << endl;
  // cout << s2.GetStrData() << endl;

  String s3;
  // s3.operator=( s1 );
  s3 = s1;    //  연산자 오버로딩 필요...
  cout << s3.GetLen() << endl;
  cout << s3.GetStrData() << endl;

  String s4( "Hello" );
  // cout << s4.GetLen() << endl;
  // cout << s4.GetStrData() << endl;
  s4 = s4;  //  미친...
  cout << s4.GetLen() << endl;
  cout << s4.GetStrData() << endl;
}
